
#include "Wanted.hpp"

using namespace utils;

int main(void)
{
    Wanted::Wanted var;

    while (var.utils.window.isOpen()) {
        var.getEvent();
        var.doLogic();
        var.draw();
    }

    return EXIT_SUCCESS;
}
