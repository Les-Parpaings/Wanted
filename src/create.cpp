
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

Game::Game(Utils &utils)
{
}

Menu::Menu(Utils &utils)
{
    // auto &map = utils.textures.getMap();

    // size_t x = 0;
    // size_t y = 0;
    // for (auto &it : map) {
    //     if (it.first.find(CHARACTER_PATH, 0, strlen(CHARACTER_PATH)) == std::string::npos)
    //         continue;

    //     std::string name = it.first;
    //     name.erase(0, strlen(CHARACTER_PATH));

    //     this->buttons.push_back(ButtonIcon());
    //     this->buttons.end().operator--()->create(I_BUTTON, R_BUTTON, IR_BUTTON, it.second, R_BUTTON, VECTOR_1, FONT_REGULAR, "oui", 50, sf::Vector2f(300 + 500 * x, 300 + 500 * y), FADE_DONE, true);

    //     y++;
    //     if (y >= 2) {
    //         x++;
    //         y = 0;
    //     }
    // }

    // newText(text, FONT_BOLD, "Choisissez un personnage", 100, sf::Vector2f(960.0f, 100.0f));
}

Wanted::Wanted() :
    utils(),
    part(WantedPart::PART_MENU),
    menu(utils),
    game(utils)
{
}

}
