
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

ButtonOnOff::ButtonOnOff()
{
}

ButtonOnOff::ButtonOnOff(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Vector2f pos, bool activated)
{
    create(texture, rect, sprite_info, pos, activated);
}

void ButtonOnOff::create(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Vector2f pos, bool activated)
{
    this->activated = activated;

    sprite = new sf::Sprite();
    newSprite(*sprite, texture, rect, pos);
    sprite_rect = sprite_info;
    if (this->activated) {
        sf::IntRect rect = sprite->getTextureRect();
        rect.left = sprite_rect.idle + sprite_rect.click;
        sprite->setTextureRect(rect);
    }
}

ButtonOnOff::ButtonOnOff(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool activated)
{
    create(font, str, size, text_info, pos, activated);
}

void ButtonOnOff::create(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool activated)
{
    this->activated = activated;

    text = new sf::Text();
    newText(*text, font, str, size, pos);
    if (this->activated) {
        text_color = COLOR_ON;
    } else {
        text_color = COLOR_OFF;
    }
    text->setFillColor(text_color.idle);
}

ButtonOnOff::ButtonOnOff(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool activated)
{
    create(texture, rect, sprite_info, font, str, size, text_info, pos, activated);
}

void ButtonOnOff::create(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, bool activated)
{
    this->activated = activated;

    sprite = new sf::Sprite();
    newSprite(*sprite, texture, rect, pos);
    sprite_rect = sprite_info;
    if (this->activated) {
        sf::IntRect rect = sprite->getTextureRect();
        rect.left = sprite_rect.idle + sprite_rect.click;
        sprite->setTextureRect(rect);
    }

    text = new sf::Text();
    newText(*text, font, str, size, pos);
    if (this->activated) {
        text_color = COLOR_ON;
    } else {
        text_color = COLOR_OFF;
    }
    text->setFillColor(text_color.idle);
}

ButtonOnOff::~ButtonOnOff()
{
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void ButtonOnOff::getRectColor(ButtonRect &rect, ButtonColor &color)
{
    if (IS_TRUE(this->activated)) {
        rect = {
            sprite_rect.idle + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
            sprite_rect.hover + sprite_rect.click,
        };
        color = COLOR_ON;
    } else {
        rect = {
            sprite_rect.idle,
            sprite_rect.hover,
            sprite_rect.hover,
        };
        color = COLOR_OFF;
    }
}

void ButtonOnOff::getEvent(sf::RenderWindow &window, int *len)
{
    ButtonRect rect;
    ButtonColor color;

    this->getRectColor(rect, color);
    this->getMousePosition(window, rect, color);
    this->getEventOnOff(window, len);
}

void ButtonOnOff::getEvent(sf::RenderWindow &window, sf::View &view, int *len)
{
    ButtonRect rect;
    ButtonColor color;

    this->getRectColor(rect, color);
    this->getMousePosition(window, view, rect, color);
    this->getEventOnOff(window, len);
}

void ButtonOnOff::getEventOnOff(sf::RenderWindow &window, int *len)
{
    if (hold)
        return;

    if (this->hover) {
        if (this->click) {
            if (this->getActivation()) {
                if (IS_DEFINED(len)) {
                    if ((*len) > 1) {
                        this->setActivation(false);
                        (*len)--;
                    }
                } else {
                    this->setActivation(false);
                }
            } else {
                this->setActivation(true);
                if (IS_DEFINED(len))
                    (*len)++;
            }
        }
    }
}

// ****************************************************************************
// ACTIVATION
// ****************************************************************************

void ButtonOnOff::setActivation(bool value)
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
    if (IS_DEFINED(text)) {
        if (value) {
            text->setFillColor(sf::Color::White);
        } else {
            text->setFillColor(sf::Color(168, 168, 168));
        }
    }
}

bool ButtonOnOff::getActivation() const
{
    return activated;
}

void ButtonOnOff::setTextOnOff(sf::String off, sf::String on)
{
    if (IS_TRUE(this->activated)) {
        setTextString(*text, on, MID);
    } else {
        setTextString(*text, off, MID);
    }
}

}
