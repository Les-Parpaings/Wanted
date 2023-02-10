
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

GameInfo::GameInfo(Utils &utils)
{
    newSprite(background, utils.textures.getTexture("none"), sf::IntRect(0, 0, 300, 1080), sf::Vector2f(1770.0f, 540.0f));

    newSprite(chosenSprite, utils.textures.getTexture("none"), R_HERO, sf::Vector2f(1770.0f, 192.0f));
    newText(chosenTitle, FONT_BOLD, standardToSFML("Wanted"), 60, sf::Vector2f(1770.0f, 92.0f));

    sf::FloatRect rect(chosenTitle.getGlobalBounds());

    newText(timeTitle, FONT_BOLD, "", 50, sf::Vector2f(rect.left, 500.0f));
    newText(timeText, FONT_REGULAR, "", 40, sf::Vector2f(rect.left, 550.0f));

    newText(roundTitle, FONT_BOLD, "", 50, sf::Vector2f(rect.left, 700.0f));
    newText(roundText, FONT_REGULAR, "", 40, sf::Vector2f(rect.left, 750.0f));

    newText(scoreTitle, FONT_BOLD, "", 50, sf::Vector2f(rect.left, 900.0f));
    newText(scoreText, FONT_REGULAR, "", 40, sf::Vector2f(rect.left, 950.0f));


    setTextString(timeTitle, "Time", LEFT);
    setTextString(roundTitle, "Round", LEFT);
    setTextString(scoreTitle, "Score", LEFT);

    setTextString(timeText, "30s", LEFT);
    setTextString(roundText, "0", LEFT);
    setTextString(scoreText, "00000", LEFT);
}

GameInfo::~GameInfo()
{
}

void GameInfo::draw(utils::Utils &utils)
{
    utils.window.draw(background);

    utils.window.draw(chosenSprite);
    utils.window.draw(chosenTitle);

    utils.window.draw(roundTitle);
    utils.window.draw(roundText);

    utils.window.draw(scoreTitle);
    utils.window.draw(scoreText);

    utils.window.draw(timeTitle);
    utils.window.draw(timeText);
}

void GameInfo::setSprite(sf::Texture &newTexture)
{
    chosenSprite.setTexture(newTexture);
}

void GameInfo::setTime(size_t newTime)
{
    setTextString(timeText, std::to_string(newTime), LEFT);
}

void GameInfo::setScore(size_t newScore)
{
    setTextString(scoreText, std::to_string(newScore), LEFT);
}

void GameInfo::setRound(size_t newRound)
{
    setTextString(roundText, std::to_string(newRound), LEFT);
}


}
