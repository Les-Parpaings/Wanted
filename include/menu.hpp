
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>

    #include <iostream>
    #include <list>

    #include "utils/utils.hpp"
    #include "common.hpp"

namespace Wanted
{

struct Game;

struct Menu {
    sf::Text score_title;
    ScoreBoard score_list;

    utils::ButtonClick start;
    utils::ButtonClick quit;

    Menu(utils::Utils &utils, ScoreBoardValue &scoreboard);
    void getEvent(utils::Utils &utils);
    void doLogic(Game &game, utils::Utils &utils, WantedPart &part);
    void draw(utils::Utils &utils);
    ~Menu();
};

} // namespace menu
