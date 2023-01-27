#ifndef SPAN_HPP
 #define SPAN_HPP

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Span {
private:
	unsigned int N;
	std::multiset<int> v;
	Span(void);
public:
	Span(unsigned int n);
	Span(const Span& s);
	~Span(void);
	Span& operator=(const Span& s);
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan(void) const;
	int longestSpan(void) const;
	unsigned int getN() const;
};

#endif