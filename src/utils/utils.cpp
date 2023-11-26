
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
// WINDOW
// ****************************************************************************

int Utils::loopValue = true;

Utils::Utils()
{
    // Check MACRO value
    #if defined(WINDOW_FPS) && WINDOW_FPS > 0
        unsigned int window_fps = WINDOW_FPS;
    #else
        unsigned int window_fps = 60;
    #endif

    #ifdef WINDOW_SIZE
        sf::VideoMode window_size = WINDOW_SIZE;
    #else
        sf::VideoMode window_size(1920, 1080);
    #endif

    #ifdef WINDOW_NAME
        std::string window_name = WINDOW_NAME;
    #else
        std::string window_name = "SFML Window";
    #endif


    //Window
    settings.antialiasingLevel = 8;
    window.create(window_size, window_name, sf::Style::Default, settings);
    icon.loadFromFile(PATH_ICON);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(window_fps);
    window.setActive(true);
    exit = false;

    //Time
    std::srand((unsigned int)(std::time(nullptr)));

    this->setupSignal();
}

Utils::~Utils()
{
}

void Utils::clear(sf::Color color)
{
    window.clear(color);
}

void Utils::draw()
{
    transition.doTransition();
    transition.draw(window);

    transition_circle.doTransition();
    transition_circle.draw(window);

    shaders.setParameter();

    window.display();
}

void Utils::getExitEvent()
{
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

bool Utils::loop()
{
    return (this->window.isOpen() && Utils::loopValue);
}

}
