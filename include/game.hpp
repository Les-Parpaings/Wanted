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

struct Game {

    std::list<sf::Sprite> heads;

    Game(utils::Utils &utils);
    void getEvent(utils::Utils &utils);
    void doLogic(utils::Utils &utils);
    void draw(utils::Utils &utils);
    ~Game();
};

} // namespace WMenu
