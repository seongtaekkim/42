#include <list>
#include "../../map.hpp"
#include <map>
#include <iostream>

int		main(void)
{
	ft::map<int, std::string> m1;
	// std::map<int, std::string> m2;

	// std::cout << m1.max_size() << std::endl;
	// std::cout << m2.max_size() << std::endl;
	m1.insert(ft::make_pair(0,"abc"));
	m1.insert(ft::make_pair(10,"abc"));
	std::cout << m1.at(10) << std::endl;
	return (0);
}
