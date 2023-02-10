
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

ButtonClick::ButtonClick()
{
    this->anim_value = FADE_OFF;
    this->one_shot = true;
}

ButtonClick::ButtonClick(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Vector2f pos, animState anim_state, bool os)
{
    create(texture, rect, sprite_info, pos, anim_state, os);
}

void ButtonClick::create(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Vector2f pos, animState anim_state, bool os)
{
    sprite = new sf::Sprite();
    newSprite(*sprite, texture, rect, pos);
    sprite_rect = sprite_info;

    this->anim_value = anim_state;
    this->one_shot = os;
}

ButtonClick::ButtonClick(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, animState anim_state, bool os)
{
    create(font, str, size, text_info, pos, anim_state, os);
}

void ButtonClick::create(sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, animState anim_state, bool os)
{
    text = new sf::Text();
    newText(*text, font, str, size, pos);
    text_color = text_info;

    this->setAnimation(anim_state);
    this->one_shot = os;
}

ButtonClick::ButtonClick(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, animState anim_state, bool os)
{
    create(texture, rect, sprite_info, font, str, size, text_info, pos, anim_state, os);
}

void ButtonClick::create(sf::Texture &texture, sf::IntRect rect, ButtonRect sprite_info, sf::Font &font, sf::String str, int size, ButtonColor text_info, sf::Vector2f pos, animState anim_state, bool os)
{
    sprite = new sf::Sprite();
    newSprite(*sprite, texture, rect, pos);
    sprite_rect = sprite_info;

    text = new sf::Text();
    newText(*text, font, str, size, pos);
    text_color = text_info;

    this->setAnimation(anim_state);
    this->one_shot = os;
}

ButtonClick::~ButtonClick()
{
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void ButtonClick::getEvent(sf::RenderWindow &window)
{
    this->getMousePosition(window, sprite_rect, text_color);
    this->getEventClick();
}

void ButtonClick::getEvent(sf::RenderWindow &window, sf::View &view)
{
    this->getMousePosition(window, view, sprite_rect, text_color);
    this->getEventClick();
}

void ButtonClick::getEventClick()
{
    if (IS_TRUE(click) && IS_TRUE(one_shot)) {
        setAnimation(FADE_OUT);
    }
}

// ****************************************************************************
// ANIMATION
// ****************************************************************************

void ButtonClick::setAnimation(animState new_value)
{
    anim_value = new_value;

    if (anim_value == FADE_OFF) {
        if (IS_DEFINED(sprite))
            sprite->setScale(VECTOR_0);
        if (IS_DEFINED(text)) {
            text->setScale(VECTOR_0);
        }
    }

    if (anim_value == FADE_DONE) {
        if (IS_DEFINED(sprite)) {
            sprite->setScale(VECTOR_1);
            sf::IntRect rect = sprite->getTextureRect();
            rect.left = this->sprite_rect.idle;
            sprite->setTextureRect(rect);
        }
        if (IS_DEFINED(text))
            text->setScale(VECTOR_1);
    }
}

animState ButtonClick::getAnimation() const
{
    return anim_value;
}

void ButtonClick::doAnimation()
{
    if (anim_value == FADE_DONE || anim_value == FADE_OFF)
        return;

    float scale = 0.0f;
    if (IS_DEFINED(sprite))
        scale = sprite->getScale().x;
    else if (IS_DEFINED(text))
        scale = text->getScale().x;
    else
        return;

    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(1)) {
        if (anim_value == FADE_IN) {
            scale += 0.10f;
            if (scale >= 1.0f) {
                this->setAnimation(FADE_DONE);
                return;
            }
        }
        if (anim_value == FADE_OUT) {
            scale -= 0.10f;
            if (scale <= 0.0f) {
                this->setAnimation(FADE_OFF);
                return;
            }
        }

        if (IS_DEFINED(sprite))
            sprite->setScale(scale, scale);
        if (IS_DEFINED(text))
            text->setScale(scale, scale);

        clock.restart();
    }
}

}
