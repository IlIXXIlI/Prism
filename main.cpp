#include "Point.h"
#include "Prism.h"
#include "Utils.h"
#include <iostream>

int main (){
    std::initializer_list<Point> points = {Point{-4, 0}
    , Point{0, 0}
    , Point{0, -4}
    , Point{-4, -4}

    };

    BasePolygon base = {points};
    std::cout << "Perimeter: " << base.perimeter()  << std::endl;
    std::cout << "Area: " << base.area()  << std::endl;
    std::cout << base << std::endl;

    Prism prism = {points, 6};
    std::cout << "Base Area: " << prism.base_area()  << std::endl;
    std::cout << "Base Perimeter: " << prism.base_perimeter()  << std::endl;
    std::cout << "Side Area: " << prism.side_area()  << std::endl;
    std::cout << "Area: " << prism.surface_area()  << std::endl;
    std::cout << "Prism volume: " << prism.volume()  << std::endl;
    std::cout << prism << std::endl ;

    return 0;
};