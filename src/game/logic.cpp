
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void doLogicNewRound(Game *var)
{
    if (var->_timeGame.getElapsedTime().asSeconds() >= 2.0f) {
        var->_part = PART_GAME_IN_ROUND;
        var->_timeGame.restart();
        var->_timeRound.restart();
    }
}

void doLogicInRound(Game *var, ScoreBoardValue &values, ScoreBoard &list, Utils &utils)
{
    if (var->_timeGame.getElapsedTime().asSeconds() >= 1.0f) {
        var->_time--;
        var->_info.setTime(var->_time);
        var->_timeGame.restart();
    }
    // not in the if clock because time can be reduce if the chosen one is not clicked
    if (var->_time == 0) {
        utils.sounds.getSound(SOUND_WRONG).stop();
        utils.sounds.play(SOUND_SCREAMER);
        var->endGame(values, list);
    }

    if (var->_roundType == RoundType::MOVE_LINE_COLS
     || var->_roundType == RoundType::MOVE_BORDEL) {
        var->doMovement();
    }

    if (var->_dark) {
        var->_darkCircle.setPosition(utils.window.mapPixelToCoords(sf::Mouse::getPosition(utils.window)));
        var->_darkCircle.setOrigin(sf::Vector2f(var->_darkCircle.getLocalBounds().left + var->_darkCircle.getLocalBounds().width / 2.0f, var->_darkCircle.getLocalBounds().top + var->_darkCircle.getLocalBounds().height / 2.0f));
    }
}

void doLogicEndRound(Game *var, sf::Music &menuMusic, Utils &utils, WantedPart &part)
{
    if (var->_isEndGame) {
        if (var->_screamerClock.getElapsedTime().asMilliseconds() >= 30) {
            var->_screamerClock.restart();

            auto rect = var->_screamer.getTextureRect();
            if (rect.top <= 13724) {
                rect.top += 722;
                var->_screamer.setTextureRect(rect);
            } else {
                part = PART_MENU;
                utils.sounds.getSound(SOUND_SCREAMER).stop();
                menuMusic.play();
            }
        }
    } else {
        if (var->_timeGame.getElapsedTime().asSeconds() >= 2.0f) {
            var->startNewRound(utils);
        }
    }
}

void Game::doLogic(Menu &menu, Utils &utils, WantedPart &part, ScoreBoardValue &scoreboard)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        part = PART_MENU;
        this->_music.stop();
        utils.sounds.getSound(SOUND_GOOD).stop();
        utils.sounds.getSound(SOUND_WRONG).stop();
        menu.music.play();
    }

    switch (_part) {
        case PART_GAME_NEW_ROUND:
            doLogicNewRound(this);
            break;
        case PART_GAME_IN_ROUND:
            doLogicInRound(this, scoreboard, menu.score_list, utils);
            break;
        case PART_GAME_END_ROUND:
            doLogicEndRound(this, menu.music, utils, part);
            break;
    }
}

}
