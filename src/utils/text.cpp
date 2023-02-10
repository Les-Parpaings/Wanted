
#include "utils/utils.hpp"

namespace utils {

void setTextString(sf::Text &text, sf::String str, TextPosition position)
{
    text.setString(str);

    const sf::FloatRect rect = text.getLocalBounds();;
    switch (position)
    {
        case TextPosition::LEFT:
            text.setOrigin(sf::Vector2f(0, rect.top + rect.height / 2));
            break;
        case TextPosition::MID:
            text.setOrigin(sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2));
            break;
        case TextPosition::RIGHT:
            text.setOrigin(sf::Vector2f(rect.left + rect.width, rect.top + rect.height / 2));
            break;
    }
}

sf::String standardToSFML(std::string str)
{
    return sf::String::fromUtf8(str.begin(), str.end());
}

void setSizeText(sf::Text &text, sf::String str, int size, TextPosition origin, float limit)
{
    float pos;

    text.setCharacterSize(size);
    setTextString(text, str, origin);
    if (origin == TextPosition::LEFT) {
        pos = text.getGlobalBounds().left + text.getGlobalBounds().width;
    } else {
        pos = text.getGlobalBounds().left;
    }

    if (origin == TextPosition::LEFT) {
        if (pos >= limit) {
            while (pos >= limit) {
                text.setCharacterSize(text.getCharacterSize() - 1);
                setTextString(text, str, origin);
                pos = text.getGlobalBounds().left + text.getGlobalBounds().width;
            }
        }
    } else {
        if (pos <= limit) {
            while (pos <= limit) {
                text.setCharacterSize(text.getCharacterSize() - 1);
                setTextString(text, str, origin);
                pos = text.getGlobalBounds().left;
            }
        }
    }
}

void setLetterPosition(sf::Text &text)
{
    sf::Vector2f bounds(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
    text.setOrigin(bounds.x, bounds.y);
    text.move(bounds.x, bounds.y);
}

}
