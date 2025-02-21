//
// Created by Дима … on 21.02.2025.
//

#ifndef PRISM_PRISM_H
#define PRISM_PRISM_H
#include "Point.h"

class Prism {
    Point* points;
    int h;
public:
    Prism(Point* base, int h);

    int base_area() const;
    int side_area();
    int surface_area();
    int volume();
};
#endif //PRISM_PRISM_H
