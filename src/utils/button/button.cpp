
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

Button::Button()
{
    hover = false;
    click = false;
    hold = false;

    this->sprite = nullptr;
    this->sprite_rect = {0, 0, 0};

    this->text = nullptr;
    this->text_color = {sf::Color::White, sf::Color::White, sf::Color::White};

    this->cursor = sf::Cursor::Type::Hand;
}

Button::~Button()
{
    if (IS_DEFINED(sprite)) {
        delete sprite;
    }
    if (IS_DEFINED(text)) {
        delete text;
    }
}

void Button::draw(sf::RenderWindow &window, const sf::RenderStates &states)
{
    sf::RenderStates renderStates;
    if (hover) {
        renderStates = states;
    } else {
        renderStates = sf::RenderStates::Default;
    }

    if (IS_DEFINED(sprite))
        window.draw((*sprite), renderStates);
    if (IS_DEFINED(text))
        window.draw((*text), renderStates);

    if (hover && Utils::cursor_type == sf::Cursor::Type::Arrow)
        Utils::cursor_type = cursor;
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void Button::getMousePosition(sf::RenderWindow &window, sf::View &view, ButtonRect s_rect, ButtonColor t_color)
{
    sf::Vector2f pos(window.mapPixelToCoords(sf::Mouse::getPosition(window), view));
    this->getEventButton(window, pos, s_rect, t_color);
}

void Button::getMousePosition(sf::RenderWindow &window, ButtonRect s_rect, ButtonColor t_color)
{
    sf::Vector2f pos(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    this->getEventButton(window, pos, s_rect, t_color);
}

void Button::getEventButton(sf::RenderWindow &window, sf::Vector2f pos, ButtonRect s_rect, ButtonColor t_color)
{
    auto button = sf::Mouse::Button::Left;
    if (sf::Mouse::isButtonPressed(button) && this->click == true) {
        hold = true;
        return;
    } else {
        hold = false;
    }

    sf::FloatRect size;
    if (IS_DEFINED(sprite)) {
        size = sprite->getGlobalBounds();
    } else if (IS_DEFINED(text)) {
        size = text->getGlobalBounds();
    } else {
        size = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    }

    int rect;
    sf::Color color;

    if (pos.x >= size.left && pos.x <= size.left + size.width
    && pos.y >= size.top && pos.y <= size.top + size.height) {
        this->hover = true;

        if (sf::Mouse::isButtonPressed(button)) {
            this->click = true;

            if(IS_DEFINED(sprite))
                rect = s_rect.click;
            if(IS_DEFINED(text))
                color = t_color.click;
        } else {
            this->click = false;

            if(IS_DEFINED(sprite))
                rect = s_rect.hover;
            if(IS_DEFINED(text))
                color = t_color.hover;
        }
    } else {
        this->hover = false;
        this->click = false;

        if(IS_DEFINED(sprite))
            rect = s_rect.idle;
        if(IS_DEFINED(text))
            color = t_color.idle;
    }

    if (IS_DEFINED(sprite))
        sprite->setTextureRect(sf::IntRect(rect, sprite->getTextureRect().top, sprite->getTextureRect().width, sprite->getTextureRect().height));
    if (IS_DEFINED(text))
        text->setFillColor(color);
}

bool Button::isHovered() const
{
    return hover;
}

bool Button::isClicked(bool do_reset)
{
    if (click && do_reset) {
        this->reset();
        return true;
    } else {
        return click;
    }
}

bool Button::isHolding()
{
    return hold;
}

bool Button::isPressed(bool do_reset)
{
    if (IS_TRUE(hold))
        return false;

    return this->isClicked(do_reset);
}

void Button::reset(bool graphic)
{
    this->hover = false;
    this->click = false;
    this->hold = false;

    if (graphic) {
        if (IS_DEFINED(sprite)) {
            sf::IntRect rect = sprite->getTextureRect();
            rect.left = this->sprite_rect.idle;
            sprite->setTextureRect(rect);
        }
        if (IS_DEFINED(text)) {
            text->setFillColor(this->text_color.idle);
        }
    }
}

// ****************************************************************************
// SFML
// ****************************************************************************

sf::Sprite *Button::getSprite()
{
    return sprite;
}

sf::Text *Button::getText()
{
    return text;
}

}
