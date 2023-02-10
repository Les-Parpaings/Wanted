
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::doLogic()
{
}

void Menu::doLogic()
{
}

void Wanted::doLogic()
{
    switch (part) {
        case WantedPart::PART_MENU:
            menu.doLogic();
            break;
        case WantedPart::PART_GAME:
            game.doLogic();
            break;
    }
}

}
