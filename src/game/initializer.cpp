
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::startNewGame(Utils &utils)
{
    this->_part = PART_GAME_NEW_ROUND;

    this->_headList.clear();
    this->_headChosen = this->_headList.end();

    this->_round = 0;
    this->_roundType = LINE_COLS;
    this->_score = 0;
    this->_time = 10;

    this->_info.setRound(_round);
    this->_info.setScore(_score);
    this->_info.setTime(_time);

    this->_isEndGame = false;

    this->_music.play();

    startNewRound(utils);
}

void Game::endGame(ScoreBoardValue &values, ScoreBoard &list)
{
    this->_screamer.setTextureRect(R_FULL_SCREEN);
    this->_screamerClock.restart();

    this->_isEndGame = true;
    this->_music.stop();
    endRound();

    setScoreboard(values, this->_score, list);
}


}
