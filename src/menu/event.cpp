
#include "Wanted.hpp"

using namespace utils;
namespace Wanted
{

void Menu::getEvent(Utils &utils)
{
    this->start.getEvent(utils.window);
    this->quit.getEvent(utils.window);
}

}
