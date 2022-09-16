
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
    : number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &input)
{
    int raw;

    std::cout << "Int constructor called" << std::endl;
    raw = input;
    raw = (raw << FRACTIONAL_BITS);
    setRawBits(raw);
}

Fixed::Fixed(const float &input)
{
    int raw;

    std::cout << "Float constructor called" << std::endl;
    raw = (int)roundf((input * (1 << FRACTIONAL_BITS)));
    setRawBits(raw);
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &f)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this == &f)
        return (*this);
    this->setRawBits(f.getRawBits());
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void    Fixed::setRawBits(int const raw)
{
    this->number = raw;   
}

// 반올림 추가 필요
float   Fixed::toFloat(void) const
{
    float   ret = (float)this->number / (1 << (FRACTIONAL_BITS-1));
    //std::cout << "test : " << ret << std::endl;
    ret = (float)this->number / (1 << FRACTIONAL_BITS);
    return (ret);
}

int Fixed::toInt(void) const
{
    return (this->number >> FRACTIONAL_BITS);
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return (out);
}