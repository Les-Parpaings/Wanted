
#include "utils/utils.hpp"
#include <functional>

namespace utils {

// ****************************************************************************
// Transition
// ****************************************************************************

Transition::Transition()
{
    image.create(1920, 1080);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(0, 0, 0, 255));

    value = FADE_DONE;
}

Transition::~Transition()
{
}

void Transition::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Transition::doTransition()
{
    if (value == FADE_IN || value == FADE_OUT)
        Utils::cursor_type = sf::Cursor::ArrowWait;

    if (clock.getElapsedTime().asMilliseconds() >= sf::Int32(5)) {
        sf::Color color = sprite.getColor();
        if (value == FADE_IN) {
            color.a += TRANS_ADD;
            if (color.a >= 255) {
                value = FADE_DONE;
                color.a = 255;
                Utils::cursor_type = sf::Cursor::Arrow;
            }
        } else if (value == FADE_OUT) {
            color.a -= TRANS_ADD;
            if (color.a <= 0) {
                value = FADE_OFF;
                color.a = 0;
                Utils::cursor_type = sf::Cursor::Arrow;
            }
        }
        sprite.setColor(color);
        clock.restart();
    }
}

void Transition::setAnimValue(animState new_value)
{
    value = new_value;

    if (value == FADE_DONE) {
        sprite.setColor(sf::Color::Black);
    } else if (value == FADE_OFF) {
        sprite.setColor(sf::Color::Transparent);
    } else {
        Utils::cursor_type = sf::Cursor::ArrowWait;
    }
}

animState Transition::getAnimValue() const
{
    return value;
}

}
