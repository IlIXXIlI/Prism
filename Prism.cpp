#include <iostream>
#include "Utils.h"
#include "Prism.h"
#include "Point.h"

Prism::Prism(Point* base, int h) : points(sort_points_polygon(base, *(&base + 1) - base)), h(h) {}

int Prism::base_area() const {

}
