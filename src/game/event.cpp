
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

static bool pictureIsClicked(sf::Sprite &sprite, sf::Vector2f posMouse)
{
    bool ret = false;
    auto rect = sprite.getGlobalBounds();

    if (posMouse.x >= rect.left && posMouse.x <= rect.left + rect.width
    && posMouse.y >= rect.top && posMouse.y <= rect.top + rect.height) {

        auto image = sprite.getTexture()->copyToImage();
        posMouse -= sf::Vector2f(rect.left, rect.top);

        if (image.getPixel(posMouse.x, posMouse.y).a > 64) {
            ret = true;
        }
    }
    return ret;
}

void Game::getEventClicked(utils::Utils &utils, bool &touched)
{
    if (touched) {
        utils.sounds.play(SOUND_GOOD);
        endRound();
    } else {
        if (_time < 5) {
            _time = 0;
        } else {
            _time -= 5;
            utils.sounds.play(SOUND_WRONG, false);
        }
        _info.setTime(_time);
    }
}

bool Game::getEventHead(utils::Utils &utils, FNAFList::iterator it, sf::Vector2f posMouse, bool &touched)
{
    if (pictureIsClicked(it->first, posMouse)) {
        if (it == _headChosen) {
            touched = true;
        } else {
            touched = false;
        }
        getEventClicked(utils, touched);
        return true;
    } else {
        return false;
    }
}

void Game::getEvent(Utils &utils)
{
    if (_part != PART_GAME_IN_ROUND)
        return;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f posMouse(utils.window.mapPixelToCoords(sf::Mouse::getPosition(utils.window)));
        bool touched = false;

        for (auto it = _headList.begin(); it != _headList.end(); it++) {
            if (getEventHead(utils, it, posMouse, touched)) {
                return;
            }
        }
    }
}

}
