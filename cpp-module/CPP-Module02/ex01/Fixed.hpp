
#ifndef FIXED_HPP
 #define FIXED_HPP
 
class Fixed
{
private:
    int number;
    static const int FRACTIONAL_BITS = 8;
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
};

std::ostream & operator << (std::ostream &out, const Fixed &f);

#endif