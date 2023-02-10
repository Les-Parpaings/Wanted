
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Menu::doLogic(Utils &utils, WantedPart &part)
{
    if (quit.isClicked())
        utils.window.close();
    if (start.isClicked())
        part = PART_GAME;
}

}
