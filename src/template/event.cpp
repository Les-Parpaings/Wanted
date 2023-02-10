
#include "template/main.hpp"

using namespace utils;
namespace MyTemplate
{

void MyTemplate::getEventAll(Utils &utils)
{
    while (utils.window.pollEvent(utils.event)) {
        utils.getExitEvent();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            utils.transition.setAnimValue(FADE_IN);

        // switch (var.part) {
        //     case :
        //         break;
        //     case :
        //         break;
        // }
    }
}

}
