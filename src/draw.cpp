
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::draw(utils::Utils &utils)
{
    int new_heros_index = getRandomInRange<int>(0, (HerosType::Size - 1));
    utils.textures.getTexture(herosList[new_heros_index]);
}

void Menu::draw(utils::Utils &utils)
{
    start.draw(utils.window);
    quit.draw(utils.window);

    utils.window.draw(score_title);
    for (auto &it : score_list)
        utils.window.draw(it);
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
