
#include "Wanted.hpp"
#include <fstream>

using namespace utils;
namespace Wanted
{

Game::Game(Utils &utils)
{
    auto map = utils.textures.getMap();
    size_t x;
    size_t y;

    for (auto &it : map) {
        heads.push_back(sf::Sprite());
        newSprite(*heads.end().operator--(), it.second, R_HERO, sf::Vector2f(256.0f + 196.0f * x, 360.0f + 196.0f * y), VECTOR_0_50);

        x++;
        if (x % 4 == 0 && x != 0) {
            x = 0;
            y++;
        }
    }
}

Menu::Menu(Utils &utils, ScoreBoardValue &scoreboard)
{
    this->start.create(FONT_BOLD, "Start", 100, BUTTON_COLOR_CLASSIC, sf::Vector2f(960.0f, 750.0f), FADE_DONE, true);
    this->quit.create(FONT_BOLD, "Quit", 100, BUTTON_COLOR_CLASSIC, sf::Vector2f(960.0f, 900.0f), FADE_DONE, true);

    newText(score_title, FONT_BOLD, "Scoreboard", 75, sf::Vector2f(960.0f, 150.0f));
    for (size_t i = 0; i < scoreboard.size(); i++) {
        score_list.push_back(sf::Text());
        newText(*score_list.end().operator--(), FONT_REGULAR, std::to_string(scoreboard[i]), 50, sf::Vector2f(960.0f, 250.0f + i * 50.0f));
    }
}

ScoreBoardValue readScoreBoard()
{
    ScoreBoardValue content;
    std::ifstream file(PATH_SCOREBOARD);
    std::string buffer;

    while (getline(file, buffer))
        content.push_back(std::stoi(buffer));
    file.close();
    return content;
}

Wanted::Wanted() :
    utils(),
    part(WantedPart::PART_MENU),
    scoreboard(readScoreBoard()),
    menu(utils, scoreboard),
    game(utils)
{
}

}
