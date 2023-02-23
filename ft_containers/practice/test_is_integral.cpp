#include <iostream>
#include <type_traits>
#include <vector>
#include <iomanip>

#include "../type_traits.hpp"


class A {};
struct B { int x= 42; };
using BF = decltype(B::x); // bit-field's type
 
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
	  SHOW( std::is_integral<BF>::value );
    SHOW( f(123) );

    SHOW( ft::is_integral<A>::value );
    SHOW( ft::is_integral<float>::value);
    SHOW( ft::is_integral<int*>::value );
    SHOW( ft::is_integral<int>::value );
    SHOW( ft::is_integral<const int>::value);
    SHOW( ft::is_integral<bool>::value );
    SHOW( ft::is_integral<char>::value );
	  SHOW( ft::is_integral<BF>::value );

	std::vector<int> v;
	bool res = 1;
	(ft::is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<int*>() == std::is_integral<int*>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<char32_t>() == std::is_integral<char32_t>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<const int>() == std::is_integral<const int>()) ? 0 : res = 0;std::cout << res << std::endl;
	(ft::is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	std::cout << res << std::endl;
	std::cout << std::is_integral<const int>() << std::endl;
}