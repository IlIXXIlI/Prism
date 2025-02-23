//
// Created by Дима … on 21.02.2025.
//

#ifndef PRISM_PRISM_H
#define PRISM_PRISM_H
#include "Point.h"
#include <iostream>

class BasePolygon {
    Point* points_;
    int n_;
    explicit BasePolygon(Point* points, int n);
public:
    static BasePolygon sort_points_polygon(Point *points, int n);
    static BasePolygon regular_polygon(Point* points, int n, int radius);
    int area() const;
    int perimeter() const;
    std::ostream& dump(std::ostream& os) const;
};


class Prism {
    BasePolygon base_;
    int h_;
public:
    Prism(BasePolygon base, int h);
    int base_area() const;
    int base_perimeter() const;
    int side_area();
    int surface_area();
    int volume();
    std::ostream& dump(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const BasePolygon& base);
std::ostream& operator<<(std::ostream& os, const Prism& prism);

#endif //PRISM_PRISM_H
