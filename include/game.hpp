
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

    Game(utils::Utils &utils);
    void getEvent(utils::Utils &utils);
    void doLogic();
    void draw(utils::Utils &utils);
    ~Game();
};

} // namespace WMenu
