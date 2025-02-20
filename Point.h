//
// Created by Дима … on 21.02.2025.
//

#ifndef PRISM_POINT_H
#define PRISM_POINT_H

class Point {
public:
    int x_, y_;
    Point(int x, int y);
    Point();

    int distance_to(Point other_point) const;
    int get_x() const;
    int get_y() const;

};

#endif //PRISM_POINT_H
