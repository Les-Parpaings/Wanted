
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Game::draw(utils::Utils &utils, sf::Sprite &staticSprite)
{
    FNAFList::iterator it;

    switch (_part)
    {
        case PART_GAME_NEW_ROUND:
            utils.window.draw(staticSprite);
            _intro.draw(utils);
            _info.draw(utils);
            break;
        case PART_GAME_IN_ROUND:
            it = _headList.end();
            while (true) {
                if (it == _headList.begin())
                    break;
                it--;
                utils.window.draw(it->first);
            }
            utils.window.draw(staticSprite);
            if (_dark) {
                utils.window.draw(_darkCircle);
            }
            _info.draw(utils);
            break;
        case PART_GAME_END_ROUND:
            if (_isEndGame) {
                utils.window.draw(_screamer);
            } else {
                utils.window.draw(_headChosen->first);
                utils.window.draw(staticSprite);
                _info.draw(utils);
            }
            break;
    }
}

void Menu::draw(utils::Utils &utils, sf::Sprite &staticSprite)
{
    utils.window.draw(this->background);
    utils.window.draw(staticSprite);
    utils.window.draw(this->title);

    start.draw(utils.window);
    quit.draw(utils.window);

    utils.window.draw(score_title);
    for (auto &it : score_list)
        utils.window.draw(it);

    if (ghostDraw) {
        utils.window.draw(ghost);
        utils.window.draw(ghostText);
    }
}

void Wanted::draw()
{
    utils.clear();

    switch (part) {
        case WantedPart::PART_MENU:
            menu.draw(utils, this->_static);
            break;
        case WantedPart::PART_GAME:
            game.draw(utils, this->_static);
            break;
    }

    utils.draw();
}

}
