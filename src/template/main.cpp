
#include "template/main.hpp"

using namespace utils;
namespace MyTemplate
{

int do_MyTemplate(Utils &utils)
{
    MyTemplate var(utils);

    utils.transition.setAnimValue(FADE_OUT);
    while (utils.window.isOpen()) {

        if (utils.transition.getAnimValue() == FADE_OFF)
            var.getEventAll(utils);
        if (utils.transition.getAnimValue() == FADE_DONE)
            break;

        // switch (var.part) {
        //     case :
        //         break;
        //     case :
        //         break;
        // }

        var.draw(utils);
    }

    return EXIT_SUCCESS;
}

} // namespace MyTemplate
