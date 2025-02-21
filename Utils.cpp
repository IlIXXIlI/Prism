#include "iostream"
#include "Point.h"

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

Point* sort_points_polygons(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (points[j].get_y() > 0 && points[j + 1].get_y() > 0) {
                if (points[j].get_x() > points[j + 1].get_x() ) {
                    Point b = points[j];
                    points[j] = points[j + 1];
                    points[j + 1] = b;
                }
            }
            else if (points[j].get_y() <= 0 && points[j + 1].get_y() <= 0) {
                if (points[j].get_x() < points[j + 1].get_x() ) {
                    Point b = points[j];
                    points[j] = points[j + 1];
                    points[j + 1] = b;
                }
            } else if (points[j].get_y() <= 0 && points[j + 1].get_y() > 0){
                Point b = points[j];
                points[j] = points[j + 1];
                points[j + 1] = b;
            }
        }
    }

    return points;

}