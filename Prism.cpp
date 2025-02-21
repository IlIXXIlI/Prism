#include "Utils.h"
#include "Prism.h"
#include "Point.h"

Prism::Prism(BasePolygon base, int h) : base_(base), h_(h){};

BasePolygon::BasePolygon(Point* points, int n) : points_(points), n_(n) {}

BasePolygon BasePolygon::sort_points_polygon(Point *points, int n) {
    return BasePolygon{sort_points_polygons(points, n), n};
}

int BasePolygon::perimeter() const {
    int tmp = 0;
    for (int i = 0; i < n_; i++) {
//        std::cout << "tmp: " << tmp << " dis: "  << points_[i].distance_to(points_[i + 1]) << std::endl;

        if (i+1 >= n_) {
            tmp += points_[i].distance_to(points_[0]);
        } else {
            tmp += points_[i].distance_to(points_[i + 1]);
        }
    }
    return tmp;
}
int BasePolygon::area() const {
    int tmp = 0;

    for (int i = 0; i < n_; i++) {
//        std::cout << "tmp: " << tmp  << " i=" << i << " Point1: " << points_[i].get_x() << ", " << points_[i+1].get_y() << std::endl;
        if (i+1 >= n_) {
            tmp += points_[i].get_x() * points_[0].get_y();
        } else {
            tmp += points_[i].get_x() * points_[i+1].get_y();
        }
    }

    for (int i = 0; i < n_; i++) {
//        std::cout << "tmp: " << tmp  << std::endl;
        if (i+1 >= n_) {
            tmp -= points_[i].get_y() * points_[0].get_x();
        } else {
            tmp -= points_[i].get_y() * points_[i+1].get_x();
        }
    }
    if (tmp < 0) {
        tmp = -tmp;
    }
    tmp = tmp/2;

    return tmp;
}

int Prism::base_area() const {
    int tmp = base_.area();
    return tmp;
}

int Prism::base_perimeter() const {
    int tmp = base_.perimeter();
    return tmp;
}