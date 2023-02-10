
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::draw(utils::Utils &utils)
{
}

void Menu::draw(utils::Utils &utils)
{
}

void Wanted::draw()
{
    utils.clear();

    switch (part) {
        case WantedPart::PART_MENU:
            menu.draw(utils);
            break;
        case WantedPart::PART_GAME:
            game.draw(utils);
            break;
    }

    utils.draw();
}

}
