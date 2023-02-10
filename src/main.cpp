
#include "project.hpp"

using namespace utils;

int main(int ac, char **av)
{
    Utils utils;
    int index = 0;
    int (*func_array[1])(Utils &) = {
        MyTemplate::do_MyTemplate
    };

    while (utils.window.isOpen()) {
        index = func_array[index](utils);
    }

    // Pause when debug mode on windows
    #if defined(_WIN32)
        #if defined(_DEBUG)
            system("pause");
        #endif
    #endif

    return EXIT_SUCCESS;
}
