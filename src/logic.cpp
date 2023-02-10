
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
}

}
