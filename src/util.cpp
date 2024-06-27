#include "util.h"
#include <random>

namespace util {

std::mt19937& GetRandomGenerator() {
	static std::random_device rd;
	static const auto seed = rd();
	static std::mt19937 rng(seed);
	return rng;
}

int GetRandomInt(int max) {
	return GetRandomInt(0, max);
}

int GetRandomInt(int min, int max) {
	std::uniform_int_distribution<int> dist(min, max);
	return dist(GetRandomGenerator());
}

float GetRandomFloat() {
	return GetRandomFloat(0.0f, 1.0f);
}

float GetRandomFloat(float min, float max_exclusive) {
	std::uniform_real_distribution<float> dist(min, max_exclusive);
	return dist(GetRandomGenerator());
}

} // namespace utils
