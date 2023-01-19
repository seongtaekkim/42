#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int					number;
    static const int	FRACTIONAL_BITS = 8;
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

	static Fixed *fmin(Fixed *lhs, Fixed *rhs);
	static Fixed *fmax(Fixed *lhs, Fixed *rhs);
	static const Fixed &fmin(const Fixed &lhs, const Fixed &rhs);
	static const Fixed &fmax(const Fixed &lhs, const Fixed &rhs);

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

std::ostream& operator<< (std::ostream& out, const Fixed &f);
#endif