
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Wanted::getEvent()
{
    while (utils.window.pollEvent(utils.event)) {
        utils.getExitEvent();

        switch (part) {
            case WantedPart::PART_MENU:
                menu.getEvent(utils);
                break;
            case WantedPart::PART_GAME:
                game.getEvent(utils);
                break;
        }
    }
}

}
