
#pragma once

    // ************************************************************************
    // IMAGE
    // ************************************************************************

    #define I_FREDDY                    utils.textures.getTexture("freddy")
    #define I_BONNIE                    utils.textures.getTexture("bonnie")
    #define I_CHICA                     utils.textures.getTexture("chica")
    #define I_FOXY                      utils.textures.getTexture("foxy")

    #define I_SCREAMER                  utils.textures.getTexture("screamer")
    #define I_MAIN_TITLE                utils.textures.getTexture("main_screen")
    #define I_STATIC                    utils.textures.getTexture("static")
    #define I_GHOST                     utils.textures.getTexture("ghost")

    #define R_ICON                      sf::IntRect(0, 0, 100, 100)
    #define R_ICON_LRG                  sf::IntRect(0, 0, 256, 256)

    #define R_FULL_SCREEN               sf::IntRect(0, 4, 1280, 720)
    #define R_GHOST                     sf::IntRect(0, 0,  200, 200)

    // ************************************************************************
    // FONT
    // ************************************************************************

    #define FONT_FNAF                   utils.fonts.getFont("FNAF")

    // ************************************************************************
    // SOUND
    // ************************************************************************

    #define SOUND_GOOD                  "FreddyLaugh"
    #define SOUND_WRONG                 "BallonBoyHaHa"
    #define SOUND_SCREAMER              "Screamer"
    #define SOUND_GHOST                 "Ghost"

    // ************************************************************************
    // MUSIC
    // ************************************************************************

    #define MUSIC_MAIN_MENU             "MainMenu"
    #define MUSIC_IN_GAME               "InGame"
    #define MUSIC_STATIC                "Static"

    // ************************************************************************
    // SHADER
    // ************************************************************************

    // #define SHADER_EXAMPLE           &utils.fonts.getShader("dir\\shader")

    // ************************************************************************
    // DATA
    // ************************************************************************

    #define PATH_SCOREBOARD             "assets/data/scores.txt"
    #define PATH_DIALOGS                "assets/data/chatGPT.txt"
    #define PATH_ICONS                  "icons/"
    #define PATH_ICONS_LRG              "icons_lrg/"

    // ************************************************************************
    // TYPEDEF
    // ************************************************************************

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>

    #include <iostream>
    #include <vector>
    #include <list>

    // All Parts here
    enum WantedPart {
        PART_MENU,
        PART_GAME
    };

    enum FNAFType {
        FREDDY,
        BONNIE,
        CHICA,
        FOXY,
        FNAF_SIZE,
    };

    enum RoundType {
        LINE_COLS,
        BORDEL,
        MOVE_LINE_COLS,
        MOVE_BORDEL,
        SIDE,
        DARK
    };

    enum SideList {
        SIDE_UP,
        SIDE_DOWN,
        SIDE_LEFT,
        SIDE_RIGHT,
    };

    typedef std::vector<size_t>                 ScoreBoardValue;
    typedef std::list<sf::Text>                 ScoreBoard;
    typedef std::pair<sf::Sprite, FNAFType>     FNAF;
    typedef std::list<FNAF>                     FNAFList;
