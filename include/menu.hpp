
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

    sf::Sprite background;
    sf::Text title;

    utils::ButtonClick start;
    utils::ButtonClick quit;

    sf::Music music;

    bool ghostDraw;
    size_t ghostIndex;
    sf::Sprite ghost;
    sf::Text ghostText;
    sf::Clock ghostClock;
    std::vector<std::string> ghostDialog;

    Menu(utils::Utils &utils, ScoreBoardValue &scoreboard);
    void getEvent(utils::Utils &utils);
    void doLogic(Game &game, utils::Utils &utils, WantedPart &part);
    void draw(utils::Utils &utils, sf::Sprite &staticSprite);
    ~Menu();
};

} // namespace menu
