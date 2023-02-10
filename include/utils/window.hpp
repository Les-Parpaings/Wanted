
#pragma once

namespace utils {

    #define WINDOW_SIZE             sf::VideoMode(1920, 1080)
    #define WINDOW_NAME             sf::String("SFML Window")
    #define WINDOW_FPS              60

    #if defined(_WIN32)
        #define PATH_ICON           "assets\\icon.png"
    #else
        #define PATH_ICON           "assets/icon.png"
    #endif

enum animState {
    FADE_OFF,
    FADE_IN,
    FADE_OUT,
    FADE_DONE
};

    #define TRANS_ADD       15

class Transition
{
    public:
        Transition();
        void draw(sf::RenderWindow &window);
        void doTransition();
        void setAnimValue(animState new_value);
        animState getAnimValue() const;
        ~Transition();

    private:
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

        animState value;
        sf::Clock clock;
};

class TransitionCircle
{
    public:
        TransitionCircle();
        void draw(sf::RenderWindow &window);
        void doTransition();
        void setAnimValue(animState new_value);
        animState getAnimValue() const;
        ~TransitionCircle();

    private:
        sf::CircleShape circle;

        animState value;
        sf::Clock clock;
};

}; // namespace utils
