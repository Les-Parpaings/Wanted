
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

/*

Round 1-5
    colonnes / lignes

Round 6-10
    Bordel

Round 11-15
    Mouvement En lignes

Round 16-20
    Mouvement randoms

Round 20+
    Full random

*/

static HeroType getRandomIndex(HeroType chosenOne)
{
    HeroType index = chosenOne;
    while (index == chosenOne)
        index = getRandom(HERO_SIZE);
    return index;
}

static void addSpriteInList(HeroList &list, std::string *nameList, HeroType &nameChosen, sf::Vector2f pos, Utils &utils)
{
    HeroType index = getRandomIndex(nameChosen);
    std::string path(PATH_HEROES + nameList[index]);

    list.push_back(Hero(sf::Sprite(), index));
    newSprite(list.end().operator--()->first, utils.textures.getTexture(path), R_HERO, pos);
}

static void createColLineRound(Game *var, Utils &utils)
{
    size_t size = var->round * 2;

    size_t x = 810 - (R_HERO.width / 2);
    size_t y = 540 - (R_HERO.height / 2);

    x -= 100 * ((size / 2) - 1);
    y -= 100 * ((size / 2) - 1);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            addSpriteInList(var->headList, var->nameList, var->nameChosen, sf::Vector2f(x, y), utils);
            x += 100;
        }
        x = (810 - (R_HERO.width / 2)) - (100 * ((size / 2) - 1));
        y += 100;
    }
}

static void createBordelRound(Game *var, Utils &utils)
{
    size_t nbr = getRandomInRange(30, 50);

    for (size_t i = 0; i < nbr; i++) {
        size_t x = getRandomInRange(0, 1620);
        size_t y = getRandomInRange(0, 1080);
        addSpriteInList(var->headList, var->nameList, var->nameChosen, sf::Vector2f(x, y), utils);
    }
}

static void createLineMovementRound(Game *var, Utils &utils)
{
    size_t size = 8;

    size_t x = 810 - (R_HERO.width / 2);
    size_t y = 540 - (R_HERO.height / 2);

    x -= 100 * ((size / 2) - 1);
    y -= 100 * ((size / 2) - 1);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            addSpriteInList(var->headList, var->nameList, var->nameChosen, sf::Vector2f(x, y), utils);
            x += 100;
        }
        x = (810 - (R_HERO.width / 2)) - (100 * ((size / 2) - 1));
        y += 100;
    }
}

static void createRandomMovementRound(Game *var, Utils &utils)
{
    size_t nbr = getRandomInRange(50, 75);

    for (size_t i = 0; i < nbr; i++) {
        size_t x = getRandomInRange(0, 1620);
        size_t y = getRandomInRange(0, 1080);
        addSpriteInList(var->headList, var->nameList, var->nameChosen, sf::Vector2f(x, y), utils);
    }
}

static void setHero(Game *var, Utils &utils)
{
    size_t index = getRandom(var->headList.size());

    var->headChosen = var->headList.begin();
    for (size_t i = 0; i < index; i++, var->headChosen++);

    sf::Texture &newTexture = utils.textures.getTexture(PATH_HEROES + var->nameList[var->nameChosen]);
    var->headChosen->first.setTexture(newTexture);
    var->headChosen->second = var->nameChosen;
    var->info.setSprite(newTexture);
    var->intro.setSprite(newTexture);
}

void Game::startNewRound(Utils &utils)
{
    part = PART_GAME_NEW_ROUND;

    void (*func[4])(Game *, Utils &) = {
        createColLineRound,
        createBordelRound,
        createLineMovementRound,
        createRandomMovementRound
    };

    headList.clear();
    headChosen = headList.end();

    this->round++;
    if (round >= 1 && round <= 5) {
        roundType = RoundType::LINE_COLS;
    } else if (round >= 6 && round <= 10) {
        roundType = RoundType::BORDEL;
    } else if (round >= 11 && round <= 15) {
        roundType = RoundType::MOVE_LINE_COLS;
    } else if (round >= 16 && round <= 20) {
        roundType = RoundType::MOVE_BORDEL;
    } else {
        roundType = static_cast<RoundType>(getRandomInRange(1, 3));
    }
    info.setRound(round);

    nameChosen = getRandom(HERO_SIZE);
    std::cout << nameChosen << std::endl;
    func[roundType](this, utils);
    setHero(this, utils);

    this->timeGame.restart();
    this->timeRound.restart();
}

void Game::endRound()
{
    part = PART_GAME_END_ROUND;

    // add score only if there is time left
    if (this->time > 0) {
        int timeElapsed = static_cast<int>(timeRound.getElapsedTime().asSeconds());
        if (timeElapsed < 10) {
            timeElapsed = 10 - timeElapsed;
            this->score += timeElapsed * 1000;
        }
        this->time += 5;
        info.setTime(time);
    }
    info.setScore(score);

    // Clear all heads except the chosen one
    Hero temp = *headChosen;
    headList.clear();
    headList.push_back(temp);

    this->timeGame.restart();
    this->timeRound.restart();
}

}
