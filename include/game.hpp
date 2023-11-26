
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
    sf::Text _chosenTitle;
    sf::Sprite _chosenSprite;

    GameIntro(utils::Utils &utils);
    void draw(utils::Utils &utils);
    void setSprite(sf::Texture &newTexture);
    ~GameIntro();
};

struct GameInfo
{
    sf::RectangleShape _background;
    sf::CircleShape _rec;
    sf::Clock _recClock;

    sf::Text _time;
    sf::Text _round;
    sf::Text _score;

    GameInfo(utils::Utils &utils);
    void draw(utils::Utils &utils);
    void setTime(size_t newTime);
    void setScore(size_t newScore);
    void setRound(size_t newRound);
    ~GameInfo();
};

struct Game
{
    GameInfo _info;
    GameIntro _intro;
    sf::Sprite _screamer;
    sf::Clock _screamerClock;

    FNAFList _headList;
    FNAFList::iterator _headChosen;
    std::string _nameList[FNAFType::FNAF_SIZE];
    FNAFType _nameChosen;

    size_t _round;
    RoundType _roundType;
    bool _dark;
    sf::CircleShape _darkCircle;

    size_t _score;

    size_t _time;
    sf::Clock _timeGame;
    sf::Clock _timeRound;
    bool _isEndGame;

    GamePart _part;

    sf::Music _music;

    Game(utils::Utils &utils);
    void getEvent(utils::Utils &utils);
    bool getEventHead(utils::Utils &utils, FNAFList::iterator it, sf::Vector2f posMouse, bool &touched);
    void getEventClicked(utils::Utils &utils, bool &touched);

    void doLogic(Menu &menu, utils::Utils &utils, WantedPart &part, ScoreBoardValue &scoreboard);
    void startNewRound(utils::Utils &utils);
    void endRound();
    void startNewGame(utils::Utils &utils);
    void endGame(ScoreBoardValue &values, ScoreBoard &list);
    void doMovement();

    void draw(utils::Utils &utils, sf::Sprite &staticSprite);
    ~Game();
};

} // namespace WMenu
