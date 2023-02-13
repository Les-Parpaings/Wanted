
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Menu::doLogic(Game &game, Utils &utils, WantedPart &part)
{
    if (quit.isClicked())
        utils.window.close();
    if (start.isClicked()) {
        part = PART_GAME;
        music.stop();
        game.startNewGame(utils);
    }
}

}
