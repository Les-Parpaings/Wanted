
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

void doLogicInRound(Game *var, ScoreBoardValue &values, ScoreBoard &list)
{
    if (var->timeGame.getElapsedTime().asSeconds() >= 1.0f) {
        var->time--;
        var->info.setTime(var->time);
        var->timeGame.restart();
    }
    // not in the if clock because time can be reduce if the chosen one is not clicked
    if (var->time == 0) {
        var->endGame(values, list);
    }

    if (var->roundType == RoundType::MOVE_LINE_COLS
     || var->roundType == RoundType::MOVE_BORDEL) {
        var->doMovement();
    }
}

void doLogicEndRound(Game *var, Utils &utils, WantedPart &part)
{
    if (var->timeGame.getElapsedTime().asSeconds() >= 2.0f) {
        if (var->isEndGame) {
            part = PART_MENU;
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
            doLogicInRound(this, scoreboard, menu.score_list);
            break;
        case PART_GAME_END_ROUND:
            doLogicEndRound(this, utils, part);
            break;
    }
}

}
