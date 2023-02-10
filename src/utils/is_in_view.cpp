
#include "utils/utils.hpp"

namespace utils {

template bool isInView<sf::Vector2f>(sf::Vector2f, sf::View &);
template bool isInView<sf::Vector2i>(sf::Vector2i, sf::View &);
template bool isInView<sf::Vector2u>(sf::Vector2u, sf::View &);

template <typename T>
bool isInView(T pos, sf::View &view)
{
    sf::Vector2f size(view.getSize().x / 2.0f, view.getSize().y / 2.0f);
    sf::Vector2f center(view.getCenter().x, view.getCenter().y);

    if (pos.x >= center.x - size.x && pos.x <= center.x + size.x
    && pos.y >= center.y - size.y && pos.y <= center.y + size.y) {
        return true;
    } else {
        return false;
    }
}

bool isMouseInView(sf::RenderWindow &window, sf::View &view)
{
    if (isInView(window.mapPixelToCoords(sf::Mouse::getPosition(window), view), view)) {
        return true;
    } else {
        return false;
    }
}

}
