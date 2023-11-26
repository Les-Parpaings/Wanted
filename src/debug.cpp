
#include "Wanted.hpp"
#include <fstream>

std::ostream &operator<<(std::ostream &flux, FNAFType const &fnaf)
{
    switch (fnaf) {
        case FREDDY:
            flux << "Freddy";
            return flux;
        case BONNIE:
            flux << "Bonnie";
            return flux;
        case CHICA:
            flux << "Chica";
            return flux;
        case FOXY:
            flux << "Foxy";
            return flux;
        default:
            return flux;
    }
}
