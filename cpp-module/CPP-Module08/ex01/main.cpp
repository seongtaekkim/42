#include "Span.hpp"

int main(void)
{

	std::cout << "========== stl test ==========" << std::endl;
    std::multiset<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(17);
	s.insert(9);
	s.insert(11);
	s.insert(9);
	s.insert(11);
	for (std::multiset<int>::iterator it = s.begin() ; it != s.end() ; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "========== default test ==========" << std::endl;
	Span sp = Span(6);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "========== exception test ==========" << std::endl;
	Span sp2 = Span(3);
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp2.addNumber(1);
		std::cout << "success!" << std::endl;
		sp2.addNumber(2);
		std::cout << "success!" << std::endl;
		sp2.addNumber(3);
		std::cout << "success!" << std::endl;
		sp2.addNumber(4);
		std::cout << "success!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "========== iterator test ==========" << std::endl;
	Span sp3 = Span(10000);
	srand(time(NULL));
	for (int i = 0 ; i < 10000 ; i++)
		sp3.addNumber(rand());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;


	std::cout << "========== iterator test2 ==========" << std::endl;
	std::vector<int> v;
	for (int i = 0 ; i < 10000 ; i++)
		v.push_back(rand());
	Span sp4 = Span(10000);
	try {
		sp4.addNumber(v.begin(), v.end());
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    return (0);
}