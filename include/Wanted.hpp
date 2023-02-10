
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

    Wanted();
    void getEvent();
    void doLogic();
    void draw();
    ~Wanted();
};

}
