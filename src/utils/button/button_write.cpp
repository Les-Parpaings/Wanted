
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

ButtonWrite::ButtonWrite()
{
    activated = false;
    only_digit = false;
    str = "";
}

ButtonWrite::ButtonWrite(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit)
{
    create(font, str, size, text_info, pos, digit);
}

void ButtonWrite::create(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit)
{
    this->activated = false;
    this->only_digit = digit;
    this->str = str;

    text = new sf::Text();
    newText(*text, font, this->str, size, pos);
    text_color = text_info;
    write_cursor.setPosition(text->getGlobalBounds());
}

ButtonWrite::ButtonWrite(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit)
{
    create(texture, rect, sprite_info, font, str, size, text_info, pos, digit);
}

void ButtonWrite::create(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool digit)
{
    this->activated = false;
    this->only_digit = digit;
    this->str = str;

    sprite = new sf::Sprite();
    newSprite(*sprite, texture, rect, pos);
    sprite_rect = sprite_info;

    text = new sf::Text();
    newText(*text, font, this->str, size, pos);
    text_color = text_info;
    write_cursor.setPosition(text->getGlobalBounds());
}

ButtonWrite::~ButtonWrite()
{
}

void ButtonWrite::draw(sf::RenderWindow &window, const sf::RenderStates &states)
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
    if (activated && IS_DEFINED(text))
        write_cursor.draw(window, states);
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void ButtonWrite::getRectColor(ButtonRect &rect)
{
    if (IS_TRUE(this->activated)) {
        rect = {
            sprite_rect.idle + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
        };
    } else {
        rect = {
            sprite_rect.idle,
            sprite_rect.hover,
            sprite_rect.hover,
        };
    }
}

void ButtonWrite::getEventMouse(sf::RenderWindow &window)
{
    ButtonRect rect;

    this->getRectColor(rect);
    this->getMousePosition(window, rect, text_color);
    this->getEventWrite();
}

void ButtonWrite::getEventMouse(sf::RenderWindow &window, sf::View &view)
{
    ButtonRect rect;

    this->getRectColor(rect);
    this->getMousePosition(window, view, rect, text_color);
    this->getEventWrite();
}

void ButtonWrite::getEventWrite()
{
    if (IS_TRUE(hold))
        return;

    if (IS_TRUE(this->hover)) {
        if (IS_TRUE(this->click)) {
            this->setActivation(true);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !IS_TRUE(click)) {
        this->setActivation(false);
    }
}

// ****************************************************************************
// ACTIVATION
// ****************************************************************************

void ButtonWrite::setActivation(bool value)
{
    activated = value;

    if (IS_DEFINED(sprite)) {
        sf::IntRect rect = sprite->getTextureRect();
        if (value) {
            rect.left = sprite_rect.idle + sprite_rect.click;
        } else {
            rect.left = sprite_rect.idle;
        }
        sprite->setTextureRect(rect);
    }
}

bool ButtonWrite::getActivation() const
{
    return activated;
}

void ButtonWrite::doLogic()
{
    if (activated)
        write_cursor.doLogic();
}

// ****************************************************************************
// Write
// ****************************************************************************

void ButtonWrite::getEventKey(sf::Event &event, sf::String banned)
{
    if (!IS_TRUE(this->activated))
        return;

    if (event.type == sf::Event::TextEntered){

        for (size_t i = 0; i < banned.getSize(); i++) {
            if (event.text.unicode == banned[i]) {
                return;
            }
        }

        if (event.text.unicode == WRITE_DELETE) {
            bool control = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                control = true;

            if (IS_TRUE(only_digit))
                this->deleteDigit(control);
            else
                this->deleteChar(control);
        } else {
            if (IS_TRUE(only_digit))
                this->addDigit(event.text.unicode);
            else
                this->addChar(event.text.unicode);
        }
        setTextString((*text), str, MID);
        if (IS_DEFINED(text))
            write_cursor.setPosition(text->getGlobalBounds());
    }
}

void ButtonWrite::addChar(sf::Uint32 character)
{
    str += character;
}

void ButtonWrite::deleteChar(bool all)
{
    if (!IS_TRUE(str.isEmpty())) {
        if (IS_TRUE(all)) {
            this->str.clear();
        } else {
            str.erase(str.getSize() - 1, 1);
        }
    }
}

void ButtonWrite::addDigit(sf::Uint32 character)
{
    if (character < '0' || character > '9')
        return;
    if (str.getSize() < 9) {
        if (str == "0")
            str.clear();
        str += character;
    }
}

void ButtonWrite::deleteDigit(bool all)
{
    if (this->str.getSize() > 1 && !IS_TRUE(all)) {
        str.erase(str.getSize() - 1, 1);
    } else {
        this->str.clear();
        this->str = "0";
    }
}

bool ButtonWrite::hasPressedEnter()
{
    if (str.getSize() == 0)
        return false;

    if (str[str.getSize() - 1] == 13) {
        str.erase(str.getSize() - 1);
        return true;
    } else {
        return false;
    }
}

sf::String ButtonWrite::getString() const
{
    return str;
}

size_t ButtonWrite::getStringValue() const
{
    size_t nbr = std::stoull(str.toAnsiString());
    return nbr;
}


// ****************************************************************************
// ****************************************************************************
// *****    CURSOR
// ****************************************************************************
// ****************************************************************************


// ****************************************************************************
// MANDATORY
// ****************************************************************************

WriteCursor::WriteCursor()
{
    this->cursor = sf::VertexArray(sf::Quads, 4);
    this->time = sf::Int32(250);
}

WriteCursor::~WriteCursor()
{
    cursor.clear();
}

void WriteCursor::draw(sf::RenderWindow &window, const sf::RenderStates &states)
{
    window.draw(cursor, states);
}

// ****************************************************************************
// LOGIC
// ****************************************************************************

void WriteCursor::setPosition(sf::FloatRect rect)
{
    sf::Vector2f pos(rect.left + rect.width + 2.5f, rect.top);

    for (size_t i = 0; i < cursor.getVertexCount(); i++) {
        cursor[i].position = pos;
        cursor[i].color = sf::Color::White;

        if (i == 1 || i == 2)
            cursor[i].position.x += 5.0f;
        if (i >= 2)
            cursor[i].position.y += rect.height;
    }
}

void WriteCursor::doLogic()
{
    if (clock.getElapsedTime().asMilliseconds() >= time) {

        for (size_t i = 0; i < cursor.getVertexCount(); i++) {
            if (cursor[i].color == sf::Color::White) {
                cursor[i].color = sf::Color::Transparent;
            } else {
                cursor[i].color = sf::Color::White;
            }
        }

        clock.restart();
    }
}

// ****************************************************************************
// GET INFO
// ****************************************************************************

sf::VertexArray &WriteCursor::getCursor()
{
    return cursor;
}

sf::Int32 WriteCursor::getTime()
{
    return time;
}

}
