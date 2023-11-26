/*
** EPITECH PROJECT, 2023
** Wanted
** File description:
** signal
*/

#include "utils/utils.hpp"
#include <signal.h>

namespace utils
{

static void signalHandler(int signal)
{
    Utils::loopValue = false;
}

void Utils::setupSignal()
{
    std::list<int> list;
    list.push_back(SIGINT);

    for (auto &sig : list) {
        if (signal(sig, &signalHandler) == SIG_ERR) {
            std::cerr << "[Error]: signal " << sig << " failed the action" << std::endl;
        }
    }
}

}
