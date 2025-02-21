#include "Utils.h"
#include "Point.h"
#include "iostream"
int main (){
    Point points[] = {Point{-4, 2}, Point{12, 6}, Point{0, -2} , Point{10, -2}, Point{6, 4}, Point{4, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    Point* s = sort_points_polygon(points, n);
    for (int i = 0; i < n; i++) {
        std::cout << s[i].get_x() << "," << s[i].get_y() << std::endl;
    }
    return 0;
};