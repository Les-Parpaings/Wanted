
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Menu::getEvent(Utils &utils)
{
    this->start.getEvent(utils.window);
    this->quit.getEvent(utils.window);

    if (utils.event.type == sf::Event::KeyPressed && utils.event.key.code == sf::Keyboard::Space) {
        if (!ghostDraw) {
            ghostClock.restart();
            ghostDraw = true;
            setTextString(ghostText, ghostDialog[ghostIndex], RIGHT);
            ghostIndex++;
            if (ghostIndex >= ghostDialog.size())
                ghostIndex = 0;
            utils.sounds.play(SOUND_GHOST);
        }
    }
}

}
