#include <list>
#include "../../map.hpp"
#include <map>
#include <iostream>
#include "../../vector.hpp"
int		main(void)
{
	ft::pair<int, char> t_pair(1,'a');
	std::cout << t_pair.first << " " << t_pair.second << std::endl;
	t_pair = ft::make_pair(2,'b'); // make_pair -> pair 생성자 -> pair copy assignment
	std::cout << t_pair.first << " " << t_pair.second << std::endl;

	ft::pair<int, char> t_pair2; // pair default 생성자

	std::cout << "test ==== " << std::endl;
	ft::vector<ft::pair<int, char> > v;
	v.push_back(ft::make_pair(1,'d')); // make_pair -> pair 생성자
	// std::cout << t_pair4.first << " " << t_pair4.second << std::endl;
	
	ft::map<int, char> m;
	ft::pair<int, char> p(1,'a');
	m.insert( p); // pair copy 생성자 
	// m.insert( ft::make_pair(1,'a')); // pair copy 생성자
	return (0);
}
