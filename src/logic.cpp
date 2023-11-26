
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Wanted::doLogic()
{
    switch (part) {
        case WantedPart::PART_MENU:
            menu.doLogic(game, utils, part);
            break;
        case WantedPart::PART_GAME:
            game.doLogic(menu, utils, part, scoreboard);
            break;
    }

    if (this->_clock.getElapsedTime().asMilliseconds() >= 30) {
        this->_clock.restart();

        auto rect = this->_static.getTextureRect();
        if (rect.top >= 5058) {
            rect.top = 4;
        } else {
            rect.top += 722;
        }
        this->_static.setTextureRect(rect);
    }
}

}
