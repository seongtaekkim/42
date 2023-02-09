#include <iostream>
#include <type_traits>
#include <vector>
#include <iomanip>

#include "../type_traits.hpp"


class A {};

template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}
 
#define SHOW(...) \
    std::cout << std::setw(29) << #__VA_ARGS__ << " == " << __VA_ARGS__ << '\n'
 

int main(void)
{
	std::cout << std::is_integral<int>() << std::endl;
	std::cout << std::is_integral<char>() << std::endl;
	std::cout << std::is_integral<std::string>() << std::endl;

	std::cout << ft::is_integral<int>() << std::endl;
	std::cout << ft::is_integral<char>() << std::endl;
	std::cout << ft::is_integral<std::string>() << std::endl;

	std::cout << std::boolalpha;
 
    SHOW( std::is_integral<A>::value );
    SHOW( std::is_integral<float>::value);
    SHOW( std::is_integral<int*>::value );
    SHOW( std::is_integral<int>::value );
    SHOW( std::is_integral<const int>::value);
    SHOW( std::is_integral<bool>::value );
    SHOW( std::is_integral<char>::value );
    SHOW( f(123) );

    SHOW( ft::is_integral<A>::value );
    SHOW( ft::is_integral<float>::value);
    SHOW( ft::is_integral<int*>::value );
    SHOW( ft::is_integral<int>::value );
    SHOW( ft::is_integral<const int>::value);
    SHOW( ft::is_integral<bool>::value );
    SHOW( ft::is_integral<char>::value );
}