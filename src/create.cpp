
#include "Wanted.hpp"
#include <fstream>
#include <cstring>

using namespace utils;
namespace Wanted
{

Game::Game(Utils &utils) :
    _info(utils),
    _intro(utils)
{
    auto map = utils.textures.getMap();
    size_t index = 0;

    for (auto &it : map) {
        if (it.first.find(PATH_ICONS) == std::string::npos)
            continue;

        std::string name = it.first;
        name.erase(0, strlen(PATH_ICONS));
        _nameList[index] = name;
        index++;
    }

    this->_dark = false;
    this->_darkCircle = sf::CircleShape(300, 20);
    this->_darkCircle.setFillColor(sf::Color::Transparent);
    this->_darkCircle.setOutlineThickness(1920.0f);
    this->_darkCircle.setOutlineColor(sf::Color::Black);
    this->_darkCircle.setOrigin(sf::Vector2f(this->_darkCircle.getLocalBounds().left + this->_darkCircle.getLocalBounds().width / 2.0f, this->_darkCircle.getLocalBounds().top + this->_darkCircle.getLocalBounds().height / 2.0f));

    this->_time = 0;
    this->_score = 0;
    this->_round = 0;

    this->_isEndGame = false;

    newMusic(this->_music, MUSIC_IN_GAME);
    newSprite(this->_screamer, I_SCREAMER, R_FULL_SCREEN, sf::Vector2f(960.0f, 540.0f), sf::Vector2f(1.5f, 1.5f));
}

Menu::Menu(Utils &utils, ScoreBoardValue &scoreboard)
{
    newSprite(this->background, I_MAIN_TITLE, R_FULL_SCREEN, sf::Vector2f(960.0f, 540.0f), sf::Vector2f(1.5f, 1.5f));
    newText(this->title, FONT_FNAF, "", 150, sf::Vector2f(50.0f, 100.0f), 3.0f, sf::Color::Red);
    setTextString(this->title, "Wanted", LEFT);

    this->start.create(FONT_FNAF, "", 100, BUTTON_COLOR_CLASSIC, sf::Vector2f(150.0f, 300.0f), FADE_DONE, true);
    setTextString(*this->start.getText(), "Start", LEFT);
    this->quit.create(FONT_FNAF, "", 100, BUTTON_COLOR_CLASSIC, sf::Vector2f(150.0f, 400.0f), FADE_DONE, true);
    setTextString(*this->quit.getText(), "Quit", LEFT);

    newText(score_title, FONT_FNAF, "", 70, sf::Vector2f(150.0f, 700.0f));
    setTextString(this->score_title, "Scoreboard", LEFT);
    for (size_t i = 0; i < scoreboard.size(); i++) {
        score_list.push_back(sf::Text());
        newText(score_list.back(), FONT_FNAF, "", 40, sf::Vector2f(200.0f, 775.0f + i * 50.0f));
        setTextString(score_list.back(), std::to_string(scoreboard[i]), LEFT);
    }

    newMusic(music, MUSIC_MAIN_MENU, true, 100.0f, true);

    ghostDraw = false;
    newSprite(ghost, I_GHOST, R_GHOST, sf::Vector2f(1780.0f, 940.0f));
    newText(ghostText, FONT_FNAF, "", 20, sf::Vector2f(1880.0f, 740.0f));

    std::ifstream file(PATH_DIALOGS);
    std::string buffer;
    while (std::getline(file, buffer)) {
        for (auto &it : buffer) {
            if (it == '|') {
                it = '\n';
            }
        }
        ghostDialog.push_back(buffer);
    }
    ghostIndex = getRandom(ghostDialog.size());
}

Wanted::Wanted() :
    utils(),
    part(WantedPart::PART_MENU),
    scoreboard(readScoreBoard()),
    menu(utils, scoreboard),
    game(utils)
{
    sf::Color color(255, 255, 255, 64);
    newSprite(this->_static, I_STATIC, R_FULL_SCREEN, sf::Vector2f(960.0f, 540.0f), sf::Vector2f(1.5f, 1.5f), color);
    newMusic(this->_music, MUSIC_STATIC, true, 30.0f, true);
}

}
