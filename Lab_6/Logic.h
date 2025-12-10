#pragma once
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

inline void Calculate(float x, float y, float &s, float &r, float &c) {
	if (y == 0) {
		throw invalid_argument("Division by zero");
	}
	r = sqrt(x * x + y * y) * sin(x);
	s = exp(x / y);
	c = max(r, s);
}