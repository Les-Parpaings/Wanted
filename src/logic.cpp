
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Wanted::doLogic()
{
    switch (part) {
        case WantedPart::PART_MENU:
            menu.doLogic(utils);
            break;
        case WantedPart::PART_GAME:
            game.doLogic(utils);
            break;
    }
}

}
