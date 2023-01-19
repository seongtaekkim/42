#include "Fixed.hpp"

Fixed::Fixed()
    : number(0)
{
}

Fixed::Fixed(const int &input)
{
    int raw;

    raw = input;
    raw = (raw << FRACTIONAL_BITS);
    setRawBits(raw);
}

Fixed::Fixed(const float &input)
{
    int raw;

    raw = roundf((input * (1 << FRACTIONAL_BITS)));
    setRawBits(raw);
}

Fixed::Fixed(const Fixed &f)
{
    *this = f;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator = (const Fixed &f)
{
    if (this == &f)
        return (*this);
    this->setRawBits(f.getRawBits());
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->number);
}

void    Fixed::setRawBits(int const raw)
{
    this->number = raw;   
}

float   Fixed::toFloat(void) const
{
    float ret = (float)this->number / (1 << FRACTIONAL_BITS);
    return (ret);
}

int Fixed::toInt(void) const
{
    return (this->number >> FRACTIONAL_BITS);
}

Fixed Fixed::operator+ (const Fixed &f) { return (this->toFloat() + f.toFloat()); };
Fixed Fixed::operator- (const Fixed &f) { return (this->toFloat() - f.toFloat()); };
Fixed Fixed::operator* (const Fixed &f) { return (this->toFloat() * f.toFloat()); };
Fixed Fixed::operator/ (const Fixed &f) { return (this->toFloat() / f.toFloat()); };

Fixed &Fixed::operator++ ()
{
	++(this->number);
	return (*this);
}
Fixed Fixed::operator++ (int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}
Fixed &Fixed::operator-- ()
{
	--(this->number);
	return (*this);
}
Fixed Fixed::operator-- (int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

bool Fixed::operator> (const Fixed &f)
{
	if (this->number > f.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator< (const Fixed &f)
{
	if (this->number < f.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator>= (const Fixed &f)
{
	if (this->number >= f.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator<= (const Fixed &f)
{
	if (this->number <= f.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator== (const Fixed &f)
{
	if (this->number == f.getRawBits())
		return (true);
	return (false);
}
bool Fixed::operator!= (const Fixed &f)
{
	if (this->number != f.getRawBits())
		return (true);
	return (false);
}

Fixed *Fixed::fmin(Fixed *lhs, Fixed *rhs) {
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}
Fixed *Fixed::fmax(Fixed *lhs, Fixed *rhs) {
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}
const Fixed &Fixed::fmin(const Fixed &lhs, const Fixed &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (rhs);
	return (lhs);
}
const Fixed &Fixed::fmax(const Fixed &lhs, const Fixed &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

std::ostream& operator<< (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}