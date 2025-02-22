#include "Point.h"
#include "Utils.h"
#include <iostream>

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

std::ostream& Point::dump(std::ostream& os) const{
    os << "Point(" << x_ << ", " << y_ <<") ";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    return point.dump(os);
}
