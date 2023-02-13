
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>

    #include <iostream>
    #include <list>

    #include "utils/utils.hpp"
    #include "common.hpp"

namespace Wanted
{

enum GamePart {
    PART_GAME_NEW_ROUND,
    PART_GAME_IN_ROUND,
    PART_GAME_END_ROUND
};

struct GameIntro
{
    sf::Text chosenTitle;
    sf::Sprite chosenSprite;

    GameIntro(utils::Utils &utils);
    void draw(utils::Utils &utils);
    void setSprite(sf::Texture &newTexture);
    ~GameIntro();
};

struct GameInfo
{
    sf::Sprite background;

    sf::Text chosenTitle;
    sf::Sprite chosenSprite;

    sf::Text timeTitle;
    sf::Text timeText;

    sf::Text scoreTitle;
    sf::Text scoreText;

    sf::Text roundTitle;
    sf::Text roundText;

    GameInfo(utils::Utils &utils);
    void draw(utils::Utils &utils);
    void setSprite(sf::Texture &newTexture);
    void setTime(size_t newTime);
    void setScore(size_t newScore);
    void setRound(size_t newRound);
    ~GameInfo();
};

struct Game
{
    GameInfo info;
    GameIntro intro;

    HeroList headList;
    HeroList::iterator headChosen;
    std::string nameList[HeroType::HERO_SIZE];
    HeroType nameChosen;

    size_t round;
    RoundType roundType;
    bool dark;
    sf::CircleShape darkCircle;

    size_t score;

    size_t time;
    sf::Clock timeGame;
    sf::Clock timeRound;
    bool isEndGame;

    GamePart part;

    sf::Music music;

    Game(utils::Utils &utils);
    void getEvent(utils::Utils &utils);

    void doLogic(Menu &menu, utils::Utils &utils, WantedPart &part, ScoreBoardValue &scoreboard);
    void startNewRound(utils::Utils &utils);
    void endRound();
    void startNewGame(utils::Utils &utils);
    void endGame(ScoreBoardValue &values, ScoreBoard &list);
    void doMovement();

    void draw(utils::Utils &utils);
    ~Game();
};

} // namespace WMenu
