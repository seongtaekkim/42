#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point(void);
	Point(const float x, const float y);
    Point(const Point &p);
    ~Point();
    Point &operator = (const Point &p);
	Fixed getX() const;
	Fixed getY() const;
};
std::ostream& operator<< (std::ostream& out, const Point& p);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif