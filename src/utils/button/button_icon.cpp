
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// MANDATORY
// ****************************************************************************

ButtonIcon::ButtonIcon()
{
}

ButtonIcon::ButtonIcon(sf::Texture &t_button, sf::IntRect r_button, ButtonRect info_button, sf::Texture &t_icon, sf::IntRect r_icon, sf::Vector2f s_icon, sf::Font &font, sf::String str, int size, sf::Vector2f pos, animState anim_state, bool os)
{
    create(t_button, r_button, info_button, t_icon, r_icon, s_icon, font, str, size, pos, anim_state, os);
}

void ButtonIcon::create(sf::Texture &t_button, sf::IntRect r_button, ButtonRect info_button, sf::Texture &t_icon, sf::IntRect r_icon, sf::Vector2f s_icon, sf::Font &font, sf::String str, int size, sf::Vector2f pos, animState anim_state, bool os)
{
    sprite = new sf::Sprite();
    newSprite(*sprite, t_button, r_button, pos);
    sprite_rect = info_button;

    text = new sf::Text();
    newText(*text, font, str, size, pos);
    text_color = BUTTON_COLOR_DEFAULT;
    text->setPosition(text->getPosition().x, sprite->getGlobalBounds().top + sprite->getGlobalBounds().height + text->getGlobalBounds().height);
    text->setFillColor(sf::Color::Transparent);
    text->setOutlineColor(sf::Color::Transparent);

    newSprite(icon, t_icon, r_icon, pos, s_icon);
    scale_init = s_icon.x;

    this->setAnimation(anim_state);
    this->one_shot = os;
}

ButtonIcon::~ButtonIcon()
{
}

void ButtonIcon::draw(sf::RenderWindow &window, const sf::RenderStates &states)
{
    window.draw(*sprite, states);
    window.draw(icon, states);
    window.draw(*text, states);
}

// ****************************************************************************
// EVENT
// ****************************************************************************

void ButtonIcon::getEventClick()
{
    if (IS_TRUE(hover) && anim_value == FADE_DONE) {
        text->setFillColor(sf::Color::White);
        text->setOutlineColor(sf::Color::Black);
    } else {
        text->setFillColor(sf::Color::Transparent);
        text->setOutlineColor(sf::Color::Transparent);
    }

    if (IS_TRUE(click) && IS_TRUE(one_shot)) {
        setAnimation(FADE_OUT);
    }
}

// ****************************************************************************
// ANIMATION
// ****************************************************************************

void ButtonIcon::setAnimation(animState new_value)
{
    anim_value = new_value;

    if (anim_value == FADE_OFF) {
        sprite->setScale(VECTOR_0);
        icon.setScale(VECTOR_0);
        text->setScale(VECTOR_0);
    }

    if (anim_value == FADE_DONE) {
        sprite->setScale(VECTOR_1);
        sf::IntRect rect = sprite->getTextureRect();
        rect.left = this->sprite_rect.idle;
        sprite->setTextureRect(rect);
        icon.setScale(scale_init, scale_init);
        text->setScale(VECTOR_1);
    }
}

void ButtonIcon::doAnimation()
{
    if (anim_value == FADE_DONE || anim_value == FADE_OFF)
        return;

    float scale = sprite->getScale().x;
    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(1)) {
        if (anim_value == FADE_IN) {
            scale += 0.10f;
            if (scale >= 1.0f) {
                this->setAnimation(FADE_DONE);
            }
        }
        if (anim_value == FADE_OUT) {
            scale -= 0.10f;
            if (scale <= 0.0f) {
                this->setAnimation(FADE_OFF);
            }
        }

        sprite->setScale(scale, scale);
        scale = scale * scale_init;
        icon.setScale(scale, scale);

        clock.restart();
    }
}

// ****************************************************************************
// GET INFO
// ****************************************************************************

sf::Sprite &ButtonIcon::getIcon()
{
    return icon;
}

}
