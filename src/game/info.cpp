
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

GameInfo::GameInfo(Utils &utils)
{
    this->_background.setSize(sf::Vector2f(1900.0f, 1060.0f));
    this->_background.setPosition(10.0f, 10.0f);
    this->_background.setFillColor(sf::Color::Transparent);
    this->_background.setOutlineColor(sf::Color::White);
    this->_background.setOutlineThickness(1.0f);

    this->_rec.setRadius(20);
    this->_rec.setPointCount(50);
    this->_rec.setPosition(20.0f, 20.0f);
    this->_rec.setFillColor(sf::Color::Red);

    newText(_round, FONT_FNAF, "", 30, sf::Vector2f(1900.0f, 40.0f));
    newText(_time, FONT_FNAF, "", 30, sf::Vector2f(1900.0f, 80.0f));
    newText(_score, FONT_FNAF, "", 30, sf::Vector2f(20.0f, 1050.0f));

    utils::setTextString(_round, "Night 1", utils::RIGHT);
    utils::setTextString(_time, "00:00", utils::RIGHT);
    utils::setTextString(_score, "score: 0", utils::LEFT);
}

GameInfo::~GameInfo()
{
}

void GameInfo::draw(utils::Utils &utils)
{
    utils.window.draw(_background);
    if (_recClock.getElapsedTime().asSeconds() >= 1.0f) {
        if (_recClock.getElapsedTime().asSeconds() >= 2.0f) {
            _recClock.restart();
        }
        utils.window.draw(_rec);
    }

    utils.window.draw(_round);
    utils.window.draw(_time);
    utils.window.draw(_score);
}

void GameInfo::setTime(size_t newTime)
{
    int seconds = newTime % 60;
    int minutes = newTime / 60;

    std::string secondsStr = "";
    if (seconds < 10)
        secondsStr += "0";
    secondsStr += std::to_string(seconds);

    std::string minutesStr = "";
    if (minutes < 10)
        minutesStr += "0";
    minutesStr += std::to_string(minutes);

    std::string str = minutesStr + ":" + secondsStr;
    setTextString(this->_time, str, RIGHT);
}

void GameInfo::setScore(size_t newScore)
{
    std::string str = "score: " + std::to_string(newScore);
    setTextString(this->_score, str, LEFT);
}

void GameInfo::setRound(size_t newRound)
{
    std::string str = "Night " + std::to_string(newRound);
    setTextString(this->_round, str, RIGHT);
}


}
