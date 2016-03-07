#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Point {

  public:
    Point();
    int x;
    int y;

    double distance(const Point &point) const;
    Point middle(const Point &point) const;
};

#endif
