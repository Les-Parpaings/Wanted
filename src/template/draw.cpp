
#include "template/main.hpp"

using namespace utils;
namespace MyTemplate
{

void MyTemplate::draw(Utils &utils)
{
    utils.clear();

    utils.window.draw(sprite);
    utils.window.draw(text);

    // switch (var.part)
    // {
    //     case :
    //         break;
    //     case :
    //         break;
    // }

    utils.draw();
}

}
