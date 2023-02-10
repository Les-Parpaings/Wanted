
#include "Wanted.hpp"
#include <fstream>
#include <cstring>

using namespace utils;
namespace Wanted
{

Game::Game(Utils &utils) :
    info(utils),
    intro(utils)
{
    auto map = utils.textures.getMap();
    size_t index = 0;

    for (auto &it : map) {
        if (it.first.find(PATH_HEROES) == std::string::npos)
            continue;

        std::string name = it.first;
        name.erase(0, strlen(PATH_HEROES));
        nameList[index] = name;
        index++;
    }

    this->time = 0;
    this->score = 0;
    this->round = 0;

    this->isEndGame = false;
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

Wanted::Wanted() :
    utils(),
    part(WantedPart::PART_MENU),
    scoreboard(readScoreBoard()),
    menu(utils, scoreboard),
    game(utils)
{
}

}
