#ifndef PRISM_UTILS_H
#define PRISM_UTILS_H
#include "Point.h"
#include "Prism.h"
#include <set>
#include <random>
int pow(int base, int exponent);
int mySqrt(int x);
Point* regular_polygons(Point* points, int n, int radius);
const double PI = 3.14;
static std::random_device rd;
static std::mt19937 rng{ rd() };
int roll_dice(int min, int max);

#endif //PRISM_UTILS_H