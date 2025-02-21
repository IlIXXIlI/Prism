//
// Created by Дима … on 21.02.2025.
//

#ifndef PRISM_PRISM_H
#define PRISM_PRISM_H
#include "Point.h"

class BasePolygon {
    Point* points_;
    int n_;
    explicit BasePolygon(Point* points, int n);
public:
    static BasePolygon sort_points_polygon(Point *points, int n);
    int area() const;
    int perimeter() const;
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
};
#endif //PRISM_PRISM_H
