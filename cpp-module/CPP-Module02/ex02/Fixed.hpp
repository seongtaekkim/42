#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int					number;
    static const int	FRACTIONAL_BITS = 8;
	float doDiv (const float& numerator, const float& denominator) const;
public:
    Fixed();
    Fixed(const int &input);
    Fixed(const float &input);
    Fixed(const Fixed &f);
    ~Fixed();
    Fixed   &operator = (const Fixed &f);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt(void) const;
    float   toFloat(void) const;

	static Fixed &min(Fixed &l, Fixed &r);
	static Fixed &max(Fixed &l, Fixed &r);
	static const Fixed &min(const Fixed &l, const Fixed &r);
	static const Fixed &max(const Fixed &l, const Fixed &r);

	bool operator>(const Fixed &f);
	bool operator<(const Fixed &f);
	bool operator>=(const Fixed &f);
	bool operator<=(const Fixed &f);
	bool operator==(const Fixed &f);
	bool operator!=(const Fixed &f);

	Fixed operator+(const Fixed &f);
	Fixed operator-(const Fixed &f);
	Fixed operator*(const Fixed &f);
	Fixed operator/(const Fixed &f);

	Fixed operator++(int);
	Fixed &operator++(void);
	Fixed operator--(int);
	Fixed &operator--(void);
};

std::ostream & operator << (std::ostream &out, const Fixed &f);

#endif