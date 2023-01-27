#include "MutantStack.hpp"
#include <list>


int main()
{
{	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(4); 
	mstack.push(737);
	MutantStack<int>::reverse_iterator it = mstack.rbegin(); 
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	std::cout << "===================== " << std::endl;
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
	std::cout << "===================== " << std::endl;
	tmp = mstack;
	tmpit = tmp.begin();
	tmpite = tmp.end();
	while (tmpit != tmpite) {
		std::cout << *tmpit << std::endl;
		++tmpit;
	}
	
	std::cout << "const_iterator ===================== " << std::endl;
	MutantStack<int> ctmp(tmp);
	const MutantStack<int>::const_iterator ctmpit = ctmp.cbegin();
	const MutantStack<int>::const_iterator ctmpite = ctmp.cend();
	for (MutantStack<int>::const_iterator it = ctmpit; it != ctmpite; ++it)
      std::cout << *it << std::endl;
}


std::cout << "list test======================" << std::endl;
{	
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3); 
	mstack.push_back(4); 
	mstack.push_back(737);
	std::list<int>::reverse_iterator it = mstack.rbegin(); 
	std::list<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	std::cout << "===================== " << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
	++it; }
	std::list<int> s(mstack);
	std::cout << "===================== " << std::endl;
	std::list<int> tmp(mstack);
	std::list<int>::iterator tmpit = tmp.begin();
	std::list<int>::iterator tmpite = tmp.end();
	while (tmpit != tmpite) {
		std::cout << *tmpit << std::endl;
		++tmpit;
	}
	std::cout << "===================== " << std::endl;
	tmp = mstack;
	tmpit = tmp.begin();
	tmpite = tmp.end();
	while (tmpit != tmpite) {
		std::cout << *tmpit << std::endl;
		++tmpit;
	}
	
	std::cout << "const_iterator ===================== " << std::endl;
	std::list<int> ctmp(tmp);
	const std::list<int>::const_iterator ctmpit = ctmp.cbegin();
	const std::list<int>::const_iterator ctmpite = ctmp.cend();
	for (std::list<int>::const_iterator it = ctmpit; it != ctmpite; ++it)
      std::cout << *it << std::endl;
}
	return 0;
}