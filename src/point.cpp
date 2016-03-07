#include "point.hpp"

using namespace std;

Point::Point() {
  this->x = 0;
  this->y = 0;
}

double Point::distance(const Point &point) const {

  double dx;
  double dy;
  double distance;

  dx = this->x - point.x;
  dy = this->y - point.y;
  distance = sqrt(dx * dx + dy * dy);

  return distance;
}

Point Point::middle(const Point &P) const {

  Point middle;

  middle.x = (P.x + this->x) / 2;
  middle.y = (P.y + this->y) / 2;

  return middle;
}
