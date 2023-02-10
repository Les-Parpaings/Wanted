
#include "Wanted.hpp"
#include <fstream>

using namespace utils;
namespace Wanted
{

void setScoreboard(ScoreBoardValue &values, size_t newValue, ScoreBoard &list)
{
    for (size_t i = 0; i < values.size(); i++) {
        if (values[i] < newValue) {
            size_t temp = values[i];
            values[i] = newValue;
            newValue = temp;
        }
    }

    size_t index = 0;
    for (auto &it : list) {
        setTextString(it, std::to_string(values[index]), MID);
        index++;
    }
}

}
