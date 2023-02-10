
#include "Wanted.hpp"
#include <fstream>

std::ostream &operator<<(std::ostream &flux, HeroType const &hero)
{
    switch (hero) {
        case CAPTAIN:
            flux << "Captain America";
            return flux;
        case DEADPOOL:
            flux << "Deadpool";
            return flux;
        case GROOT:
            flux << "Groot";
            return flux;
        case HULK:
            flux << "Hulk";
            return flux;
        case IRONMAN:
            flux << "Iron Man";
            return flux;
        case SPIDERMAN:
            flux << "Spider Man";
            return flux;
        case THOR:
            flux << "Thor";
            return flux;
        case WOLVERINE:
            flux << "Wolverine";
            return flux;
        default:
            return flux;
    }
}
