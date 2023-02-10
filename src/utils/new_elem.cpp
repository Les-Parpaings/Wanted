
#include "utils/utils.hpp"

namespace utils {

//Use to create a sfml text
void newText(sf::Text &text, sf::Font &font, sf::String str, int size, sf::Vector2f pos, float thickness, sf::Color color, float angle, sf::Vector2f scale)
{
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setOrigin(sf::Vector2f(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f));
    text.setPosition(pos);
    text.setFillColor(color);
    text.setOutlineThickness(thickness);
    text.setRotation(angle);
    text.setScale(scale);
}

//Use to create a sfml sprite
void newSprite(sf::Sprite &sprite, sf::Texture &texture, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale, sf::Color color, float angle)
{
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
    sprite.setPosition(pos);
    sprite.setColor(color);
    sprite.setRotation(angle);
    sprite.setScale(scale);
}

void newMusic(sf::Music &music, std::string path, bool loop, float volume, bool play)
{
    music.openFromFile(path);
    music.setLoop(loop);
    music.setVolume(volume);
    if (IS_TRUE(play))
        music.play();
}

}
