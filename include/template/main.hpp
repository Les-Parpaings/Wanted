
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>

    #include <iostream>
    #include <string>
    #include <map>

    #include "utils/utils.hpp"
    #include "app.hpp"

namespace MyTemplate
{

// All Parts here
enum MyTemplatePart {
};

struct MyTemplate {
    MyTemplatePart part;

    sf::Sprite sprite;
    sf::Text text;

    MyTemplate(utils::Utils &utils);
    void getEventAll(utils::Utils &utils);
    void draw(utils::Utils &utils);
    ~MyTemplate();
};

int do_MyTemplate(utils::Utils &utils);

} // namespace MyTemplate
