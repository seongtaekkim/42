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


/*
	std::cout << std::endl;
	std::cout << "ab : " << ba << std::endl;
	std::cout << "pb : " << bp << std::endl;

	std::cout << "bc : " << cb << std::endl;
	std::cout << "pc : " << cp << std::endl;
	
	std::cout << "ca : " << ac << std::endl;
	std::cout << "pa : " << ap << std::endl;

	std::cout << std::endl;
	std::cout << "ab * pb : " << (ba * bp) << " " << (ba * bp).toFloat() <<  std::endl;
	std::cout << "bc * pc : " << (cb * cp) << " " << (cb * cp).toFloat() <<  std::endl;
	std::cout << "ca * pa : " << ac * ap << " " << (ac * ap).toFloat() <<  std::endl;
*/
	Fixed det_b(ba * bp);
	Fixed det_a(ac * ap);
	Fixed det_c(cb * cp);
	if (det_a.getRawBits() > 0 && det_b.getRawBits() > 0 && det_c.getRawBits() > 0)
		return (true);
	if (det_a.getRawBits() <= 0 && det_b.getRawBits() <= 0 && det_c.getRawBits() <= 0)
		return (true);
	return false;
}