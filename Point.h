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
    std::ostream& dump(std::ostream& os) const;

};
std::ostream& operator<<(std::ostream & os, const Point& point);
#endif //PRISM_POINT_H
