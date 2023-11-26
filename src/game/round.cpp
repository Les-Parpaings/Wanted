
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

Round 21-25
    sides

Round 26-30
    in the dark


*/

static FNAFType getRandomIndex(FNAFType chosenOne)
{
    FNAFType index = chosenOne;
    while (index == chosenOne)
        index = getRandom(FNAF_SIZE);
    return index;
}

static void addSpriteInList(FNAFList &list, std::string *nameList, FNAFType &nameChosen, sf::Vector2f pos, Utils &utils)
{
    FNAFType index = getRandomIndex(nameChosen);
    std::string path(PATH_ICONS + nameList[index]);

    list.push_back(FNAF(sf::Sprite(), index));
    newSprite(list.end().operator--()->first, utils.textures.getTexture(path), R_ICON, pos);
}

static void createColLineRound(Game *var, Utils &utils)
{
    size_t size = var->_round * 2;

    size_t x = 960 - (R_ICON.width / 2);
    size_t y = 540 - (R_ICON.height / 2);

    x -= 110 * (size - 1);
    y -= 110 * ((size / 2) - 1);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size * 2; j++) {
            addSpriteInList(var->_headList, var->_nameList, var->_nameChosen, sf::Vector2f(x, y), utils);
            x += 110;
        }
        x = (960 - (R_ICON.width / 2)) - (110 * (size - 1));
        y += 110;
    }
}

static void createBordelRound(Game *var, Utils &utils)
{
    size_t nbr = getRandomInRange(50, 100);

    for (size_t i = 0; i < nbr; i++) {
        size_t x = getRandomInRange(0, 1620);
        size_t y = getRandomInRange(0, 1080);
        addSpriteInList(var->_headList, var->_nameList, var->_nameChosen, sf::Vector2f(x, y), utils);
    }
}

static void createLineMovementRound(Game *var, Utils &utils)
{
    size_t size = 8;

    size_t x = 960 - (R_ICON.width / 2);
    size_t y = 540 - (R_ICON.height / 2);

    x -= 110 * ((size / 2) - 1);
    y -= 110 * ((size / 2) - 1);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            addSpriteInList(var->_headList, var->_nameList, var->_nameChosen, sf::Vector2f(x, y), utils);
            x += 110;
        }
        x = (960 - (R_ICON.width / 2)) - (110 * ((size / 2) - 1));
        y += 110;
    }
}

static void createRandomMovementRound(Game *var, Utils &utils)
{
    size_t nbr = getRandomInRange(75, 150);

    for (size_t i = 0; i < nbr; i++) {
        size_t x = getRandomInRange(0, 1620);
        size_t y = getRandomInRange(0, 1080);
        addSpriteInList(var->_headList, var->_nameList, var->_nameChosen, sf::Vector2f(x, y), utils);
    }
}

static void createSideRound(Game *var, Utils &utils)
{
    size_t side = getRandom(4);
    size_t nbr = 0;
    sf::Vector2f pos;

    switch (side) {
        case SIDE_UP:
            pos = sf::Vector2f(135.0f, 0.0f);
            nbr = 12;
            break;
        case SIDE_DOWN:
            pos = sf::Vector2f(135.0f, 1080.0f);
            nbr = 12;
            break;
        case SIDE_LEFT:
            pos = sf::Vector2f(0.0f, 100.0f);
            nbr = 7;
            break;
        case SIDE_RIGHT:
            pos = sf::Vector2f(1920.0f, 100.0f);
            nbr = 7;
            break;
    }

    for (size_t i = 0; i < nbr; i++) {
        addSpriteInList(var->_headList, var->_nameList, var->_nameChosen, pos, utils);

        if (side == SIDE_UP || side == SIDE_DOWN)
            pos.x += 150.0f;
        if (side == SIDE_LEFT || side == SIDE_RIGHT)
            pos.y += 150.0f;
    }
}

static void createDarkRound(Game *var, Utils &utils)
{
    const size_t size = 3;
    size_t alea = getRandom(size);
    void (*func[size])(Game *, Utils &) = {
        createBordelRound,
        createLineMovementRound,
        createRandomMovementRound
    };

    var->_dark = true;
    func[alea](var, utils);
    switch (alea) {
        case 0:
            var->_roundType = RoundType::BORDEL;
            break;
        case 1:
            var->_roundType = RoundType::MOVE_LINE_COLS;
            break;
        case 2:
            var->_roundType = RoundType::MOVE_BORDEL;
            break;
    }
}

static void setFNAF(Game *var, Utils &utils)
{
    size_t index = getRandom(var->_headList.size());

    var->_headChosen = var->_headList.begin();
    for (size_t i = 0; i < index; i++, var->_headChosen++);

    sf::Texture &icon = utils.textures.getTexture(PATH_ICONS + var->_nameList[var->_nameChosen]);
    sf::Texture &iconLrg = utils.textures.getTexture(PATH_ICONS_LRG + var->_nameList[var->_nameChosen]);
    var->_headChosen->first.setTexture(icon);
    var->_headChosen->second = var->_nameChosen;
    var->_intro.setSprite(iconLrg);
}

void Game::startNewRound(Utils &utils)
{
    _part = PART_GAME_NEW_ROUND;

    void (*func[6])(Game *, Utils &) = {
        createColLineRound,
        createBordelRound,
        createLineMovementRound,
        createRandomMovementRound,
        createSideRound,
        createDarkRound
    };

    _headList.clear();
    _headChosen = _headList.end();
    _dark = false;

    _round++;
    if (_round >= 1 && _round <= 4) {
        _roundType = RoundType::LINE_COLS;
    } else if (_round >= 5 && _round <= 9) {
        _roundType = RoundType::BORDEL;
    } else if (_round >= 10 && _round <= 14) {
        _roundType = RoundType::MOVE_LINE_COLS;
    } else if (_round >= 15 && _round <= 19) {
        _roundType = RoundType::MOVE_BORDEL;
    } else if (_round >= 20 && _round <= 24) {
        _roundType = RoundType::SIDE;
    } else if (_round >= 25 && _round <= 29) {
        _roundType = RoundType::DARK;
    } else {
        _roundType = static_cast<RoundType>(getRandomInRange(1, 5));
    }
    _info.setRound(_round);

    _nameChosen = getRandom(FNAF_SIZE);
    func[_roundType](this, utils);
    setFNAF(this, utils);

    _timeGame.restart();
    _timeRound.restart();
}

void Game::endRound()
{
    _part = PART_GAME_END_ROUND;

    // add score only if there is time left
    if (_time > 0) {
        int timeElapsed = static_cast<int>(_timeRound.getElapsedTime().asSeconds());
        if (timeElapsed < 10) {
            timeElapsed = 10 - timeElapsed;
            _score += timeElapsed * 1000;
        }
        _time += 5;
        _info.setTime(_time);
    }
    _info.setScore(_score);


    // Clear all heads except the chosen one
    FNAF temp = *_headChosen;
    _headList.clear();
    _headList.push_back(temp);
    _headChosen = _headList.begin();

    _timeGame.restart();
    _timeRound.restart();
}

}
