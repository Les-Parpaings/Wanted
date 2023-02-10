
#include "utils/random.hpp"
#include <bitset>
#include <random>
#include <chrono>
#include <iostream>

namespace utils
{

template signed char        getRandom<signed char>                  (signed char);
template signed short       getRandom<signed short>                 (signed short);
template signed int         getRandom<signed int>                   (signed int);
template signed long long   getRandom<signed long long>             (signed long long);
template unsigned char      getRandom<unsigned char>                (unsigned char);
template unsigned short     getRandom<unsigned short>               (unsigned short);
template unsigned int       getRandom<unsigned int>                 (unsigned int);
template unsigned long long getRandom<unsigned long long>           (unsigned long long);

template signed char        getRandomInRange<signed char>           (signed char,           signed char);
template signed short       getRandomInRange<signed short>          (signed short,          signed short);
template signed int         getRandomInRange<signed int>            (signed int,            signed int);
template signed long long   getRandomInRange<signed long long>      (signed long long,      signed long long);
template unsigned char      getRandomInRange<unsigned char>         (unsigned char,         unsigned char);
template unsigned short     getRandomInRange<unsigned short>        (unsigned short,        unsigned short);
template unsigned int       getRandomInRange<unsigned int>          (unsigned int,          unsigned int);
template unsigned long long getRandomInRange<unsigned long long>    (unsigned long long,    unsigned long long);

template <typename T>
T getRandom(T max)
{
    if (max <= 0)
        return 0;

    std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> distribution(0, max - 1);

    T nbr = (T)distribution(gen);

    return nbr;
}

template <typename T>
T getRandomInRange(T min, T max)
{
    if (max <= min)
        return min;

    std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> distribution(min, max);

    T nbr = (T)distribution(gen);

    return nbr;
}

} // namespace Random
