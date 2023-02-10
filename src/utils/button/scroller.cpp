
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

Scroller::Scroller()
{
    this->str = "";
    this->pos = {0, 0, 0};
    this->value = {0, 0, 0};
    this->result = 0;
    this->direction = HORIZONTAL;

    this->bar = nullptr;
    this->left = nullptr;
    this->right = nullptr;

    this->cursor = sf::Cursor::Type::Hand;
}

Scroller::~Scroller()
{
    if (IS_DEFINED(bar))
        delete bar;
    if (IS_DEFINED(left))
        delete left;
    if (IS_DEFINED(right))
        delete right;
}

void Scroller::create(sf::Texture &texture, sf::IntRect rect, ButtonRect rect_info, sf::Vector2f pos, int direction, int pos_min, int pos_max, int value_min, int value_max, int value_result)
{
    this->sprite = new sf::Sprite();

    this->direction = direction;
    this->pos.min = pos_min;
    this->pos.max = pos_max;
    this->pos.diff = this->pos.max - this->pos.min;
    this->value.min = value_min;
    this->value.max = value_max;
    this->value.diff = this->value.max - this->value.min;
    this->result = value_result;

    // Fraction pour avoir la taille en pixel d'une valeur, on multiplie par la valeur mis, on ajoute le min pour se caler au bon endroit
    int calcul = this->pos.min + (this->pos.diff / this->value.diff) * (this->result - this->value.min);
    sf::Vector2f but_pos = pos;
    float rotate = 0.0f;
    if (this->direction == HORIZONTAL)
        but_pos.x = (float)(calcul);
    if (this->direction == VERTICAL) {
        but_pos.y = (float)(calcul);
        rotate = 90.0f;
    }

    newSprite((*sprite), texture, rect, but_pos, VECTOR_1, sf::Color::White, rotate);
    sprite_rect = rect_info;
    this->setCursorPosition(sprite->getPosition().x);

    this->bar = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

void Scroller::createBackground(sf::Texture &texture, sf::IntRect rect_side, sf::IntRect rect_bar)
{
    sf::Vector2f pos = sprite->getPosition();

    this->left  = new sf::Sprite();
    this->right = new sf::Sprite();
    this->bar   = new sf::Sprite();

    newSprite(*left, texture, rect_side, pos);
    newSprite(*right, texture, rect_side, pos);
    newSprite(*bar, texture, rect_bar, pos);

    if (direction == HORIZONTAL) {
        left->setPosition(this->pos.min - this->sprite->getGlobalBounds().width / 2.0f - this->left->getGlobalBounds().width / 2.0f, pos.y);
        right->setPosition(this->pos.max + this->sprite->getGlobalBounds().width / 2.0f + this->right->getGlobalBounds().width / 2.0f, pos.y);
        bar->setPosition((float)(this->pos.min - this->left->getGlobalBounds().width / 2.0f), pos.y);
        bar->setOrigin(0.0f, bar->getOrigin().y);
        bar->setScale((float)(this->pos.max - this->pos.min + this->left->getGlobalBounds().width), 1.0f);
    } else if (direction == VERTICAL) {
        left->rotate(90.0f);
        right->rotate(90.0f);
        bar->rotate(90.0f);

        left->setPosition(pos.x, this->pos.min - this->sprite->getGlobalBounds().height / 2.0f - this->left->getGlobalBounds().height / 2.0f);
        right->setPosition(pos.x, this->pos.max + this->sprite->getGlobalBounds().height / 2.0f + this->right->getGlobalBounds().height / 2.0f);
        bar->setPosition(pos.x, (float)(this->pos.min - this->left->getGlobalBounds().height / 2.0f));
        bar->setOrigin(0.0f, bar->getOrigin().y);
        bar->setScale((float)(this->pos.max - this->pos.min + this->left->getGlobalBounds().height), 1.0f);
    }
}

void Scroller::createText(sf::Font &font, sf::Vector2f pos)
{
    this->text = new sf::Text();

    this->str = std::to_string(result) + "s";
    newText((*text), font, str, 75, pos);

    this->setCursorValue();
}

void Scroller::draw(sf::RenderWindow &window)
{
    if (IS_DEFINED(bar))
        window.draw(*bar);
    if (IS_DEFINED(left))
        window.draw(*left);
    if (IS_DEFINED(right))
        window.draw(*right);
    if (IS_DEFINED(sprite))
        window.draw(*sprite);
    if (IS_DEFINED(text))
        window.draw(*text);

    if (hover && Utils::cursor_type == sf::Cursor::Type::Arrow)
        Utils::cursor_type = cursor;
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void Scroller::getEvent(sf::RenderWindow &window)
{
    this->getMousePosition(window, sprite_rect, text_color);
    this->getEventScroller(window);
}

void Scroller::getEvent(sf::RenderWindow &window, sf::View &view)
{
    this->getMousePosition(window, view, sprite_rect, text_color);
    this->getEventScroller(window);
}

void Scroller::getEventScroller(sf::RenderWindow &window)
{
    if (IS_TRUE(this->hover)) {
        if (IS_TRUE(this->click)) {
            if (this->direction == HORIZONTAL)
                this->setCursorPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x);
            if (this->direction == VERTICAL)
                this->setCursorPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y);
        }
    }
}

void Scroller::setCursorPosition(float coord, bool create)
{
    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(1) || create) {

        sf::Vector2f s_pos(sprite->getPosition());
        if (coord < pos.min)
            coord = (float)(pos.min);
        if (coord > pos.max)
            coord = (float)(pos.max);
        result = (((int)(coord) - pos.min) * value.diff) / pos.diff + value.min;

        if (this->direction == HORIZONTAL) {
            s_pos.x = coord;
            if (IS_DEFINED(text)) {
                this->setCursorValue();
            }
        }
        if (this->direction == VERTICAL) {
            s_pos.y = coord;
            if (IS_DEFINED(text)) {
                this->setCursorValue();
            }
        }
        sprite->setPosition(s_pos);

        clock.restart();
    }
}

void Scroller::setCursorValue()
{
    if (result < 10) {
        str = "0" + std::to_string(result) + "s";
    } else {
        str = std::to_string(result) + "s";
    }
    setTextString((*text), str, MID);
}

// ****************************************************************************
// CONFIGURATION
// ****************************************************************************

int Scroller::getResult() const
{
    return result;
}

scrollDiff Scroller::getPosInfo() const
{
    return pos;
}

scrollDiff Scroller::getValueInfo() const
{
    return value;
}

void Scroller::changeMaxPos(int value)
{
    this->pos.max = value;
    this->pos.diff = this->pos.max - this->pos.min;
}

void Scroller::changeMaxValue(int value)
{
    this->value.max = value;
    this->value.diff = this->value.max - this->value.min;
}

}
