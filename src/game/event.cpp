
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

static bool pictureIsClicked(sf::Sprite &sprite, sf::Vector2f &posMouse)
{
    bool ret = false;
    auto rect = sprite.getGlobalBounds();

    if (posMouse.x >= rect.left && posMouse.x <= rect.left + rect.width
    && posMouse.y >= rect.top && posMouse.y <= rect.top + rect.height) {

        auto image = sprite.getTexture()->copyToImage();
        posMouse -= sf::Vector2f(rect.left, rect.top);

        if (image.getPixel(posMouse.x, posMouse.y).a > 0) {
            ret = true;
        }
    }
    return ret;
}

void Game::getEvent(Utils &utils)
{
    if (part != PART_GAME_IN_ROUND)
        return;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f posMouse(utils.window.mapPixelToCoords(sf::Mouse::getPosition(utils.window)));
        bool touched = false;
        bool clicked = false;

        for (auto it = headList.begin(); it != headList.end(); it++) {
            if (pictureIsClicked(it->first, posMouse)) {
                clicked = true;
                if (it == headChosen) {
                    touched = true;
                } else {
                    touched = false;
                }
            }
        }

        if (clicked) {
            if (touched) {
                endRound();
            } else {
                if (time < 5)
                    time = 0;
                else
                    time -= 5;
                info.setTime(time);
            }
        }
    }
}

}
