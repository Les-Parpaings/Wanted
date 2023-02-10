
#include "template/main.hpp"

using namespace utils;
namespace MyTemplate
{

MyTemplate::MyTemplate(Utils &utils)
{
    // part =

    newSprite(sprite, utils.textures.getTexture("sfml_logo"), sf::IntRect(0, 0, 1024, 1024), sf::Vector2f(960.0f, 440.0f), VECTOR_0_50);
    newText(text, utils.fonts.getFont("ubuntu_regular"), "Hello World !", 125, sf::Vector2f(960.0f, 840.0f));
}

}
