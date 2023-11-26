
#pragma once

    #include <iostream>
    #include <vector>

    #include "utils/utils.hpp"
    #include "common.hpp"
    #include "menu.hpp"
    #include "game.hpp"

namespace Wanted
{

struct Wanted
{
    utils::Utils utils;
    WantedPart part;
    ScoreBoardValue scoreboard;

    Menu menu;
    Game game;

    sf::Sprite _static;
    sf::Music _music;
    sf::Clock _clock;

    Wanted();
    void getEvent();
    void doLogic();
    void draw();
    ~Wanted();
};

void setScoreboard(ScoreBoardValue &values, size_t newValue, ScoreBoard &list);
ScoreBoardValue readScoreBoard();
void saveScoreboard(ScoreBoardValue &values);

}

std::ostream &operator<<(std::ostream &flux, FNAFType const &fnaf);
