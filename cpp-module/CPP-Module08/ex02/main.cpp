#include "MutantStack.hpp"

#include <list>
int main()
{
	
{	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(4); 
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::reverse_iterator it = mstack.rbegin(); 
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
	++it; }
	std::stack<int> s(mstack);
	std::cout << "===================== " << std::endl;
	MutantStack<int> tmp(mstack);
	MutantStack<int>::iterator tmpit = tmp.begin();
	MutantStack<int>::iterator tmpite = tmp.end();
	while (tmpit != tmpite) {
		std::cout << *tmpit << std::endl;
		++tmpit;
	}
	 tmp = mstack;
	tmpit = tmp.begin();
	tmpite = tmp.end();
	while (tmpit != tmpite) {
		std::cout << *tmpit << std::endl;
		++tmpit;
	}
	}
	

	
	return 0;
}