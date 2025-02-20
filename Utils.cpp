//
// Created by Дима … on 21.02.2025.
//
#include "iostream"

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