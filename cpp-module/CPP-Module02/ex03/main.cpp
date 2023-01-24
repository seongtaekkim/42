#include "Point.hpp"

int main(void) {
  Point a(1.0, 1.0);
  Point b(3.0, 3.0);
  Point c(1.0, 3.0);
  Point k1(2.0, 2.0);
  Point k2(2.0, 3.1);
  
  std::cout << "Point a is " << a << std::endl;
  std::cout << "Point b is " << b << std::endl;
  std::cout << "Point c is " << c << std::endl;
  std::cout << "Point k1 is " << k1 << std::endl;
  std::cout << "Point k2 is " << k2 << std::endl;

  if (bsp(a, b, c, k1) == true)
	  std::cout << "k1 : inside!" << std::endl;
  else
  	std::cout << "k1 : outside!" << std::endl;

  if (bsp(a, b, c, k2) == true)
	  std::cout << "k2 : inside!" << std::endl;
  else
  	std::cout << "k2 : outside!" << std::endl;

  return 0;
}