
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Menu::doLogic(Utils &utils)
{
    if (quit.isClicked())
        utils.window.close();
}

}
