
#pragma once

    #include <iostream>
    #include <list>

    #include "utils/utils.hpp"
    #include "app.hpp"
    #include "menu.hpp"
    #include "game.hpp"

namespace Wanted
{

// All Parts here
enum WantedPart {
    PART_MENU,
    PART_GAME
};

struct Wanted
{
    utils::Utils utils;
    WantedPart part;

    Menu menu;
    Game game;

    Wanted();
    void getEvent();
    void doLogic();
    void draw();
    ~Wanted();
};

}
