#include "iostream"
#include "Point.h"
#include "Utils.h"
#include <initializer_list>

int pow(int base, int exponent) {
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}


int mySqrt(int x) {
    if (x < 0) {
        throw std::invalid_argument("Нельзя вычесть корень из числа ниже 0");
    }

    if (x == 0 || x == 1) {
        return x;
    }

    double guess = x / 2.0;
    double epsilon = 0.00001;

    while (true) {
        double nextGuess = (guess + x / guess) / 2.0;
        if (abs(nextGuess - guess) < epsilon) {
            return nextGuess;
        }
        guess = nextGuess;
    }
}



int roll_dice(int min, int max) {
    std::uniform_int_distribution<int> uid(min, max);
    return uid(rng);
}

Point* regular_polygons(int n, int radius) {
    int centerX = 0, centerY = 0;

    for(int i = 0; i < n; ++i) {
        double angle = 2 * PI * i / n;
        int x = centerX + radius;
    }
}