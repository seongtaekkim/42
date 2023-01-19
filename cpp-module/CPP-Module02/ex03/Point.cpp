#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float x, const float y)
	: x(x), y(y) { }

Point::Point(const Point &p) {
	*this = p;
}

Point::~Point() {}

Point& Point::operator = (const Point& p) {
	if (this == &p)
		return (*this);
	const_cast<Fixed&>(this->x) = p.getX();
	const_cast<Fixed&>(this->y) = p.getY();
	return (*this);
}

Fixed Point::getX() const {
	return (this->x);
}
Fixed Point::getY() const {
	return (this->y);
}

std::ostream& operator<< (std::ostream& out, const Point& p) {
	out << "x : "  << p.getX() << ", y : " << p.getY();
	return (out);
}