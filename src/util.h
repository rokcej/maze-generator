#pragma once

namespace util {

// Returns random integer from range [0, max]
int GetRandomInt(int max);
// Returns random integer from range [min, max]
int GetRandomInt(int min, int max);

// Returns random float from range [0, 1)
float GetRandomFloat();
// Returns random float from range [min, max_exclusive)
float GetRandomFloat(float min, float max_exclusive);

} // namespace utils
