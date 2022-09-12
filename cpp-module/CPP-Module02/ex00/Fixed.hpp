class Fixed
{
private:
    int number;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &f);
    ~Fixed();
    Fixed &operator = (const Fixed &f);
    int getRawBits(void) const;
    void    setRawBits(int const raw);
};