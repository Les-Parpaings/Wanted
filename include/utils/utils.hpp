
#pragma once

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/Network.hpp>

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <list>

    #include "assets.hpp"
    #include "window.hpp"
    #include "button.hpp"
    #include "scroller.hpp"
    #include "random.hpp"

namespace utils {

    #define IS_TRUE(var)            (var == true)
    #define IS_DEFINED(var)         (var != nullptr)
    #define NONE                    -1
    #define ROOT                    0

    #define ON          true
    #define OFF         false

    #define VECTOR_0            sf::Vector2f(0.0f, 0.0f)
    #define VECTOR_1            sf::Vector2f(1.0f, 1.0f)
    #define VECTOR_2            sf::Vector2f(2.0f, 2.0f)
    #define VECTOR_3            sf::Vector2f(3.0f, 3.0f)
    #define VECTOR_4            sf::Vector2f(4.0f, 4.0f)
    #define VECTOR_5            sf::Vector2f(5.0f, 5.0f)
    #define VECTOR_6            sf::Vector2f(6.0f, 6.0f)
    #define VECTOR_7            sf::Vector2f(7.0f, 7.0f)
    #define VECTOR_8            sf::Vector2f(8.0f, 8.0f)
    #define VECTOR_9            sf::Vector2f(9.0f, 9.0f)
    #define VECTOR_10           sf::Vector2f(10.0f, 10.0f)

    #define VECTOR_1_MINUS      sf::Vector2f(-1.0f, -1.0f)
    #define VECTOR_2_MINUS      sf::Vector2f(-2.0f, -2.0f)
    #define VECTOR_3_MINUS      sf::Vector2f(-3.0f, -3.0f)
    #define VECTOR_4_MINUS      sf::Vector2f(-4.0f, -4.0f)
    #define VECTOR_5_MINUS      sf::Vector2f(-5.0f, -5.0f)
    #define VECTOR_6_MINUS      sf::Vector2f(-6.0f, -6.0f)
    #define VECTOR_7_MINUS      sf::Vector2f(-7.0f, -7.0f)
    #define VECTOR_8_MINUS      sf::Vector2f(-8.0f, -8.0f)
    #define VECTOR_9_MINUS      sf::Vector2f(-9.0f, -9.0f)
    #define VECTOR_10_MINUS     sf::Vector2f(-10.0f, -10.0f)

    #define VECTOR_0_25         sf::Vector2f(0.25f, 0.25f)
    #define VECTOR_0_33         sf::Vector2f(0.33f, 0.33f)
    #define VECTOR_0_50         sf::Vector2f(0.50, 0.50)
    #define VECTOR_0_66         sf::Vector2f(0.66f, 0.66f)
    #define VECTOR_0_75         sf::Vector2f(0.75f, 0.75f)

    #define RECT_DEFAULT            sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y)

enum TextPosition {
    LEFT,
    MID,
    RIGHT
};

enum Accents {
    NoBreakSpace = 0xA0,
    InvertedExclamation,
    Cent,
    Pound,
    Currency,
    Yen,
    BrokenBar,
    Paragraph,
    Diearesis,
    Copyright,
    FeminineOrdinalIndicator,
    LeftDoubleQuotation,
    NotSign,
    SoftHyphen,
    Registered,
    Macron,
    Degree,
    PlusMinus,
    SupperScript2,
    SupperScript3,
    Acute,
    Micro,
    Pilcrow,
    MiddleDot,
    Cedilla,
    SupperScript1,
    MasculineOrdinal,
    RightDoubleQuotation,
    FractionOneQuarter,
    FractionOneHalf,
    FractionThreeQuarter,
    InvertedQuestion,
    CapAGrave,
    CapAAcute,
    CapACircumflex,
    CapATilde,
    CapADiaeresis,
    CapARing,
    CapAE,
    CapCCedilla,
    CapEGrave,
    CapEAcute,
    CapECircumflex,
    CapEDiaeresis,
    CapIGrave,
    CapIAcute,
    CapICircumflex,
    CapIDiaeresis,
    CapETH,
    CapNTilde,
    CapOGrave,
    CapOAcute,
    CapOCircumflex,
    CapOTilde,
    CapODiaeresis,
    Multiplication,
    CapOStroke,
    CapUGrave,
    CapUAcute,
    CapUCircumflex,
    CapUDiaeresis,
    CapYAcute,
    CapThorn,
    SharpS,
    AGrave,
    AAcute,
    ACircumflex,
    ATilde,
    ADiaeresis,
    ARing,
    AE,
    CCedilla,
    EGrave,
    EAcute,
    ECircumflex,
    EDiaeresis,
    IGrave,
    IAcute,
    ICircumflex,
    IDiaeresis,
    ETH,
    NTilde,
    OGrave,
    OAcute,
    OCircumflex,
    OTilde,
    ODiaeresis,
    Division,
    OStroke,
    UGrave,
    UAcute,
    UCircumflex,
    UDiaeresis,
    YAcute,
    Thorn,
    YDiaeresis,
};

class Utils
{
    public:
        static int cursor_type;

        sf::RenderWindow window;
        sf::Event event;

        Transition transition;
        TransitionCircle transition_circle;

        Textures textures;
        Fonts fonts;
        Sounds sounds;
        Shaders shaders;

        Utils();

        /// \brief Draw cursor and display everythings that has been drawn berfore
        void draw();
        /// \brief Clear the window and draw the Background
        /// \param color The color of the background. Black by default
        void clear(sf::Color color = sf::Color::Black);


        /// \brief Check if the exit button is pressed
        void getExitEvent();

        ~Utils();

    private:
        sf::Image icon;
        sf::ContextSettings settings;
        sf::Cursor cursor;
        sf::Clock cursor_clock;

        bool exit;
};

// ****************************************************************************
//  NEW ELEMENT
// ****************************************************************************

void newText(sf::Text &text, sf::Font &font, sf::String str, int size, sf::Vector2f pos, float thickness = 3.0f, sf::Color color = sf::Color::White, float angle = 0.0f, sf::Vector2f scale = VECTOR_1);
void newSprite(sf::Sprite &sprite, sf::Texture &texture, sf::IntRect rect, sf::Vector2f pos, sf::Vector2f scale = VECTOR_1, sf::Color color = sf::Color::White, float angle = 0.0f);
void newMusic(sf::Music &music, std::string path, bool loop = true, float volume = 100.0f, bool play = false);

// ****************************************************************************
//  TEXT MANIPULATION
// ****************************************************************************

void setTextString(sf::Text &text, sf::String str, TextPosition position);
sf::String standardToSFML(std::string str);
void setSizeText(sf::Text &text, sf::String str, int size, TextPosition origin, float limit);
void setLetterPosition(sf::Text &text);

// ****************************************************************************
//  FILE MANIPULATION
// ****************************************************************************

void readLine(std::string &buffer, std::vector<std::string> &content, std::string separator = "");
std::vector<std::string> readFile(std::string path);
void writeLine(std::ofstream &file, std::vector<std::string> &content, char separator = ',');
void writeFile(std::string path, std::vector<std::string> &content, bool trunc = true);
template <typename T>
std::streampos getFileLine(T &fs, size_t line);

// ****************************************************************************
//  VIEW MANIPULATION
// ****************************************************************************

template <typename T>
bool isInView(T pos, sf::View &view);
bool isMouseInView(sf::RenderWindow &window, sf::View &view);

// ****************************************************************************
//  DEBUG
// ****************************************************************************

template <typename T>
void printVector(const T pos);
template <typename T>
void printRect(const T pos);

}; // namespace utils
