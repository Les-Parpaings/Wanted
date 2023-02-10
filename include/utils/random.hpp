
#pragma once

namespace utils {

/// \brief Generate a random number between 0 and max - 1. 0 <= nbr < max
/// \param max
/// \tparam char
/// \tparam short
/// \tparam int
/// \tparam long_long
/// \return number generated
template <typename T> T getRandom(T max);

/// \brief Generate a random number between min and max. min <= nbr <= max
/// \param min
/// \param max
/// \tparam char
/// \tparam short
/// \tparam int
/// \tparam long long
/// \return number generated
template <typename T> T getRandomInRange(T min, T max);

}; // namespace utils
