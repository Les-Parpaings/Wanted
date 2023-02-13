
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::startNewGame(Utils &utils)
{
    this->part = PART_GAME_NEW_ROUND;

    this->headList.clear();
    this->headChosen = this->headList.end();

    this->round = 0;
    this->roundType = LINE_COLS;
    this->score = 0;
    this->time = 10;

    this->info.setRound(1);
    this->info.setScore(0);
    this->info.setTime(10);

    this->isEndGame = false;

    music.play();

    startNewRound(utils);
}

void Game::endGame(ScoreBoardValue &values, ScoreBoard &list)
{
    this->isEndGame = true;
    music.stop();
    endRound();

    setScoreboard(values, this->score, list);
}


}
