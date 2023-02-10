
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void doSpriteMovement(Hero &hero)
{
    switch (hero.second) {
        case HeroType::CAPTAIN:
            hero.first.move(5.0f, 0.0f);
            return;
        case HeroType::DEADPOOL:
            hero.first.move(-5.0f, 0.0f);
            return;
        case HeroType::GROOT:
            hero.first.move(0.0f, 5.0f);
            return;
        case HeroType::HULK:
            hero.first.move(0.0f, -5.0f);
            return;
        case HeroType::IRONMAN:
            hero.first.move(5.0f, 5.0f);
            return;
        case HeroType::SPIDERMAN:
            hero.first.move(-5.0f, 5.0f);
            return;
        case HeroType::THOR:
            hero.first.move(5.0f, -5.0f);
            return;
        case HeroType::WOLVERINE:
            hero.first.move(-5.0f, -5.0f);
            return;
        default:
            return;
    }
}

void checkOutBounds(sf::Sprite &sprite)
{
    if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < 0.0f)
        sprite.setPosition(1620.0f + sprite.getGlobalBounds().width / 2.0f, sprite.getPosition().y);
    if (sprite.getGlobalBounds().left > 1620.0f)
        sprite.setPosition(0.0f - sprite.getGlobalBounds().width / 2.0f, sprite.getPosition().y);
    if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height < 0.0f)
        sprite.setPosition(sprite.getPosition().x, 1080.0f + sprite.getGlobalBounds().height / 2.0f);
    if (sprite.getGlobalBounds().top > 1080.0f)
        sprite.setPosition(sprite.getPosition().x, 0.0f - sprite.getGlobalBounds().height / 2.0f);
}

void Game::doMovement()
{
    for (auto &it : this->headList) {
        doSpriteMovement(it);
        checkOutBounds(it.first);
    }
}

}
