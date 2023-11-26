
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

    if (ghostClock.getElapsedTime().asSeconds() >= 5.0f)
        ghostDraw = false;
}

}
