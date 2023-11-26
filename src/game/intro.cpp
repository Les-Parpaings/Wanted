
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

GameIntro::GameIntro(utils::Utils &utils)
{
    newSprite(_chosenSprite, utils.textures.getTexture("none"), R_ICON_LRG, sf::Vector2f(960.0f, 540.0f));
    newText(_chosenTitle, FONT_FNAF, "Wanted", 100, sf::Vector2f(960.0f, 250.0f));
}

GameIntro::~GameIntro()
{
}

void GameIntro::draw(utils::Utils &utils)
{
    utils.window.draw(_chosenSprite);
    utils.window.draw(_chosenTitle);
}

void GameIntro::setSprite(sf::Texture &newTexture)
{
    _chosenSprite.setTexture(newTexture);
}


}
