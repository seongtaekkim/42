#include "Point.hpp"

Point operator-(const Point& p1, const Point& p2) {
  return Point(((p1.getX()) - (p2.getX())).toFloat(), (p1.getY() - p2.getY()).toFloat());
}

Fixed operator*(const Point& p1, const Point& p2) {
  return Fixed((p1.getX() * p2.getY()) -  p2.getX() * p1.getY());
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Point ba = a - b;
	Point bp = point - b;
	Point cb = b - c;
	Point cp = point - c;
	Point ac = c - a;
	Point ap = point - a;

	Fixed det_b(ba * bp);
	Fixed det_a(ac * ap);
	Fixed det_c(cb * cp);
	if (det_a.getRawBits() > 0 && det_b.getRawBits() > 0 && det_c.getRawBits() > 0)
		return (true);
	if (det_a.getRawBits() <= 0 && det_b.getRawBits() <= 0 && det_c.getRawBits() <= 0)
		return (true);
	return false;
}