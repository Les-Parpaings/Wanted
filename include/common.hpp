
#pragma once

    // ************************************************************************
    // IMAGE
    // ************************************************************************

    #define I_CAPTAIN                   utils.textures.getTexture("captain")
    #define I_DEADPOOL                  utils.textures.getTexture("deadpool")
    #define I_GROOT                     utils.textures.getTexture("groot")
    #define I_HULK                      utils.textures.getTexture("hulk")
    #define I_IRONMAN                   utils.textures.getTexture("ironman")
    #define I_SPIDERMAN                 utils.textures.getTexture("spiderman")
    #define I_THOR                      utils.textures.getTexture("thor")
    #define I_WOLVERINE                 utils.textures.getTexture("wolverine")

    #define R_HERO                      sf::IntRect(0, 0, 128, 128)

    // ************************************************************************
    // FONT
    // ************************************************************************

    #define FONT_REGULAR                utils.fonts.getFont("ubuntu_regular")
    #define FONT_BOLD                   utils.fonts.getFont("ubuntu_bold")
    #define FONT_LIGHT                  utils.fonts.getFont("ubuntu_light")

    // ************************************************************************
    // SOUND
    // ************************************************************************

    // #define SOUND_EXAMPLE            utils.sounds.getSound("dir\\sound")

    // ************************************************************************
    // MUSIC
    // ************************************************************************

    // #define MUSIC_EXAMPLE            "dir\\music"

    // ************************************************************************
    // SHADER
    // ************************************************************************

    // #define SHADER_EXAMPLE           &utils.fonts.getShader("dir\\shader")

    // ************************************************************************
    // DATA
    // ************************************************************************

    #define PATH_SCOREBOARD             "assets/data/scores.txt"

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

    typedef std::vector<size_t> ScoreBoardValue;
    typedef std::list<sf::Text> ScoreBoard;

    // All Parts here
    enum WantedPart {
        PART_MENU,
        PART_GAME
    };
