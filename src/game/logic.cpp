
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void doLogicNewRound(Game *var)
{
    if (var->timeGame.getElapsedTime().asSeconds() >= 2.0f) {
        var->part = PART_GAME_IN_ROUND;
        var->timeGame.restart();
        var->timeRound.restart();
    }
}

void doLogicInRound(Game *var, ScoreBoardValue &values, ScoreBoard &list, Utils &utils)
{
    if (var->timeGame.getElapsedTime().asSeconds() >= 1.0f) {
        var->time--;
        var->info.setTime(var->time);
        var->timeGame.restart();
    }
    // not in the if clock because time can be reduce if the chosen one is not clicked
    if (var->time == 0) {
        utils.sounds.play("end_game");
        var->endGame(values, list);
    }

    if (var->roundType == RoundType::MOVE_LINE_COLS
     || var->roundType == RoundType::MOVE_BORDEL) {
        var->doMovement();
    }

    if (var->dark) {
        var->darkCircle.setPosition(utils.window.mapPixelToCoords(sf::Mouse::getPosition(utils.window)));
        var->darkCircle.setOrigin(sf::Vector2f(var->darkCircle.getLocalBounds().left + var->darkCircle.getLocalBounds().width / 2.0f, var->darkCircle.getLocalBounds().top + var->darkCircle.getLocalBounds().height / 2.0f));
    }
}

void doLogicEndRound(Game *var, sf::Music &menuMusic, Utils &utils, WantedPart &part)
{
    if (var->timeGame.getElapsedTime().asSeconds() >= 2.0f) {
        if (var->isEndGame) {
            part = PART_MENU;
            menuMusic.play();
        } else {
            var->startNewRound(utils);
        }
    }
}

void Game::doLogic(Menu &menu, Utils &utils, WantedPart &part, ScoreBoardValue &scoreboard)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        part = PART_MENU;

    switch (this->part) {
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
