//
// Created by Дима … on 21.02.2025.
//

#ifndef PRISM_PRISM_H
#define PRISM_PRISM_H
#include "Point.h"
#include <iostream>
#include <initializer_list>

class BasePolygon {
protected:
    Point* points_;
    int n_;
    Point* sort_points_polygons(Point* points_, int n);
public:
    BasePolygon(std::initializer_list<Point> points);
    virtual ~BasePolygon();
    int area() const;
    int perimeter() const;
    virtual std::ostream& dump(std::ostream& os) const;
};


class Prism final : public BasePolygon  {
    int h_;
public:
    Prism(std::initializer_list<Point> points, int h);
    int base_area() const;
    int base_perimeter() const;
    int side_area();
    int surface_area();
    int volume();
    std::ostream& dump(std::ostream& os) const override;
};
std::ostream& operator<<(std::ostream& os, const BasePolygon& base);

#endif //PRISM_PRISM_H
