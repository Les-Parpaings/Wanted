
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>

    #include <iostream>
    #include <list>

    #include "utils/utils.hpp"
    #include "app.hpp"

namespace Wanted
{

struct Menu {
    sf::Text score_title;
    ScoreBoard score_list;

    utils::ButtonClick start;
    utils::ButtonClick quit;

    Menu(utils::Utils &utils, ScoreBoardValue &scoreboard);
    void getEvent(utils::Utils &utils);
    void doLogic(utils::Utils &utils);
    void draw(utils::Utils &utils);
    ~Menu();
};

void setScoreboard(ScoreBoardValue &values, size_t newValue, ScoreBoard &list);

} // namespace menu
