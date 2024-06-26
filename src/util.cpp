#include "util.h"
#include <random>

namespace util {

int GetRandom(int max) {
	return GetRandom(0, max);
}

int GetRandom(int min, int max) {
	static std::random_device rd;
	static const auto seed = rd();
	static std::mt19937 rng(seed);

	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

} // namespace utils
