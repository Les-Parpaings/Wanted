
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void doSpriteMovement(FNAF &fnaf, size_t index)
{
    switch (index) {
        case 0:
            fnaf.first.move(5.0f, 0.0f);
            break;
        case 1:
            fnaf.first.move(-5.0f, 0.0f);
            break;
        case 2:
            fnaf.first.move(0.0f, 5.0f);
            break;
        case 3:
            fnaf.first.move(0.0f, -5.0f);
            break;
        case 4:
            fnaf.first.move(5.0f, 5.0f);
            break;
        case 5:
            fnaf.first.move(5.0f, -5.0f);
            break;
        case 6:
            fnaf.first.move(-5.0f, 5.0f);
            break;
        case 7:
            fnaf.first.move(-5.0f, -5.0f);
            break;
    }
}

void checkOutBounds(sf::Sprite &sprite)
{
    if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < 0.0f)
        sprite.setPosition(1920.0f + sprite.getGlobalBounds().width / 2.0f, sprite.getPosition().y);
    if (sprite.getGlobalBounds().left > 1920.0f)
        sprite.setPosition(0.0f - sprite.getGlobalBounds().width / 2.0f, sprite.getPosition().y);
    if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height < 0.0f)
        sprite.setPosition(sprite.getPosition().x, 1080.0f + sprite.getGlobalBounds().height / 2.0f);
    if (sprite.getGlobalBounds().top > 1080.0f)
        sprite.setPosition(sprite.getPosition().x, 0.0f - sprite.getGlobalBounds().height / 2.0f);
}

void Game::doMovement()
{
    size_t index = 0;

    for (auto &it : this->_headList) {
        doSpriteMovement(it, index);
        checkOutBounds(it.first);
        index++;
        if (index >= 8) {
            index = 0;
        }
    }
}

}
