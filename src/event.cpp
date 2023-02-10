
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::getEvent(Utils &utils)
{
}

void Wanted::getEvent()
{
    while (utils.window.pollEvent(utils.event)) {
        utils.getExitEvent();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            setScoreboard(this->scoreboard, getRandom(10000), this->menu.score_list);
        }

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
