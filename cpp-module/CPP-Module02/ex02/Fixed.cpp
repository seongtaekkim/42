#include "Fixed.hpp"

Fixed::Fixed() : number(0) {}

Fixed::Fixed(const int& input)
{
    int raw;

    raw = input;
    raw = (raw << FRACTIONAL_BITS);
    setRawBits(raw);
}

Fixed::Fixed(const float& input)
{
    int raw;

    raw = roundf((input * (1 << FRACTIONAL_BITS)));
    setRawBits(raw);
}

Fixed::Fixed(const Fixed& f)
{
    *this = f;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator = (const Fixed& f)
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

void Fixed::setRawBits(int const raw)
{
    this->number = raw;   
}

float Fixed::toFloat(void) const
{
    float ret = float(this->number) / (1 << FRACTIONAL_BITS);
    return (ret);
}

int Fixed::toInt(void) const
{
    return (this->number >> FRACTIONAL_BITS);
}

float Fixed::doDiv (const float& numerator, const float& denominator) const {
    if (denominator == 0)
        throw std::overflow_error("Divide by zero exception");
    return (numerator / denominator);
}

Fixed Fixed::operator+ (const Fixed &f) { return (this->toFloat() + f.toFloat()); };
Fixed Fixed::operator- (const Fixed &f) { return (this->toFloat() - f.toFloat()); };
Fixed Fixed::operator* (const Fixed &f) { return (this->toFloat() * f.toFloat()); };
Fixed Fixed::operator/ (const Fixed &f) {
    try {
		return (doDiv (this->toFloat(), f.toFloat()));
	} catch (std::overflow_error &e) {
        std::cout << e.what() << std::endl;
		return (Fixed());
    }
};

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

Fixed &Fixed::min(Fixed &l, Fixed &r) {
	if (l > r)
		return (r);
	return (l);
}

Fixed &Fixed::max(Fixed &l, Fixed &r) {
	if (l > r)
		return (l);
	return (r);
}

const Fixed &Fixed::min(const Fixed &l, const Fixed &r) {
	if (l.getRawBits() > r.getRawBits())
		return (r);
	return (l);
}
const Fixed &Fixed::max(const Fixed &l, const Fixed &r) {
	if (l.getRawBits() > r.getRawBits())
		return (l);
	return (r);
}

std::ostream& operator<< (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}