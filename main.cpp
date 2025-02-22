#include "Point.h"
#include "Prism.h"
#include <iostream>

int main (){
    Point points[] = {Point{-1, 5}
    , Point{3, 7}
    , Point{11, 5}
    , Point{12, -1}
    , Point{4, -3}
    , Point{8, 3}
    , Point{-2, 4}
    };
    int n = sizeof(points) / sizeof(points[0]);

    BasePolygon base = BasePolygon::sort_points_polygon(points, n);
    std::cout << "Perimeter: " << base.perimeter()  << std::endl;
    std::cout << "Area: " << base.area()  << std::endl;
    std::cout << base << std::endl;

    Prism prism = {base, 6};
    std::cout << "Base Area: " << prism.base_area()  << std::endl;
    std::cout << "Side Area: " << prism.side_area()  << std::endl;
    std::cout << "Prism volume: " << prism.volume()  << std::endl;
    std::cout << prism;

    return 0;
};