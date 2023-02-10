
#include "utils/utils.hpp"

namespace utils {

// ****************************************************************************
//  PRINT VECTOR
// ****************************************************************************

template void printVector(sf::Vector2f);
template void printVector(sf::Vector2i);
template void printVector(sf::Vector2u);

template <typename T>
void printVector(const T pos)
{
    std::cout
        << "x: " << pos.x
        << ", y: " << pos.y
    << std::endl;
}

// ****************************************************************************
//  PRINT RECT
// ****************************************************************************

template void printRect(sf::IntRect);
template void printRect(sf::FloatRect);

template <typename T>
void printRect(const T rect)
{
    std::cout
        << "left: " << rect.left
        << ", top: " << rect.top
        << ", width: " << rect.width
        << ", height: " << rect.height
    << std::endl;
}

}
