#include "Data.hpp"

#include<stdio.h>
int main(void)
{
	Data d("seongtki", 1, 175.4, 40.44);
	std::cout << &d << std::endl << std::endl;
	std::cout << d;

	uintptr_t p = serialize(&d);
	showData(p);
	return (0);
}
