
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

GameIntro::GameIntro(utils::Utils &utils)
{
    newSprite(chosenSprite, utils.textures.getTexture("none"), R_HERO, sf::Vector2f(810.0f, 540.0f), VECTOR_3);
    newText(chosenTitle, FONT_BOLD, "Wanted", 100, sf::Vector2f(810.0f, 300.0f));
}

GameIntro::~GameIntro()
{
}

void GameIntro::draw(utils::Utils &utils)
{
    utils.window.draw(chosenSprite);
    utils.window.draw(chosenTitle);
}

void GameIntro::setSprite(sf::Texture &newTexture)
{
    chosenSprite.setTexture(newTexture);
}


}
