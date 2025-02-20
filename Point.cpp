//
// Created by Дима … on 21.02.2025.
//
#include "iostream"
#include "Point.h"
#include "Utils.h"

Point::Point(int x, int y) : x_(x), y_(y) {}
Point::Point() : x_(0), y_(0) {}

int Point::distance_to(Point other_point) const {
    int result = mySqrt(pow((x_ - other_point.x_), 2) + pow((y_ - other_point.y_), 2));
    return result;
};

int Point::get_x() const {
    return x_;
}
int Point::get_y() const {
    return y_;
}