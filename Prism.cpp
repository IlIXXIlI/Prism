#include "Prism.h"
#include "Point.h"
#include "Utils.h"
#include <initializer_list>

Prism::Prism(std::initializer_list<Point> points, int h) : BasePolygon(points), h_(h) {};

BasePolygon::BasePolygon(std::initializer_list<Point> points) :
points_(sort_points_polygons(const_cast<Point*>(points.begin()), points.size())), n_(points.size()) {}

Point* BasePolygon::sort_points_polygons(Point* points_, int n) {
    int averageY = 0;
    for (int i = 0; i < n; i++) {


        averageY += points_[i].get_y();

    }
    averageY /= n;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - (i + 1); j++) {

            if (points_[j].get_y() > averageY && points_[j + 1].get_y() > averageY) {
                if (points_[j].get_x() > points_[j + 1].get_x() ) {
                    Point b = points_[j];
                    points_[j] = points_[j + 1];
                    points_[j + 1] = b;
                }
            }
            else if (points_[j].get_y() <= averageY && points_[j + 1].get_y() <= averageY) {

                if (points_[j].get_x() < points_[j + 1].get_x()) {
                    Point b = points_[j];
                    points_[j] = points_[j + 1];
                    points_[j + 1] = b;
                }
            } else if (points_[j].get_y() <= averageY && points_[j + 1].get_y() > averageY){
                Point b = points_[j];
                points_[j] = points_[j + 1];
                points_[j + 1] = b;
            }
        }
    }



    return points_;
}
int BasePolygon::perimeter() const {
    int tmp = 0;
    for (int i = 0; i < n_; i++) {

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
        if (i+1 >= n_) {
            tmp += points_[i].get_x() * points_[0].get_y();
        } else {
            tmp += points_[i].get_x() * points_[i+1].get_y();
        }
    }

    for (int i = 0; i < n_; i++) {
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
    int tmp = this->area();
    return tmp;
}

int Prism::base_perimeter() const {
    int tmp = perimeter();
    return tmp;
}

int Prism::side_area() {
    int tmp = this->perimeter() * h_;
    return tmp;
}

int Prism::surface_area() {
    int tmp = this->side_area() + 2 * Prism::base_area();
    return tmp;

}

int Prism::volume() {
    int temp = this->area() * h_;
    return temp;
}

std::ostream& BasePolygon::dump(std::ostream &os) const {
    for (int i = 0; i < n_; i++ ) {
        os << points_[i];
        if (i != n_-1) os << " ";
    }
    return os;
}

BasePolygon::~BasePolygon() {}


std::ostream& operator<<(std::ostream& os, const BasePolygon& base)
{
    return base.dump(os);
}

std::ostream& Prism::dump(std::ostream &os) const {
    os << "Prism(Base: Base(";
    BasePolygon::dump(os);
    os << "), Height: " << h_ << ")";
    return os;
}