#include "Span.hpp"

Span::Span(void) : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::~Span() {}

Span::Span(const Span &s) : N(s.getN()) {
    this->v = s.v;
}

Span& Span::operator=(const Span& s) {
	if (this == &s)
		return (*this);
	if (this->getN() > 0) {
		this->v.clear();
	}
    this->N = s.N;
    this->v = s.v;
    return (*this);
}

void Span::addNumber(int number) {
	if (this->getN() == this->v.size())
		throw std::out_of_range("out of range exception !!");
	this->v.insert(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->getN() < static_cast<unsigned int>(std::distance(begin, end)))
		throw std::out_of_range("out of range exception !!");
	for (std::vector<int>::iterator it = begin ; it != end ; it++)
		this->v.insert(*it);
}

int Span::shortestSpan(void) const {
	if (this->getN() == 0 || this->getN() == 1 || this->v.size() == 0 || this->v.size() == 1)
		throw std::runtime_error("stl's size is 0 or 1");
	int before;
	int cur;
	int min = INT_MAX;
	std::multiset<int>::iterator tmp = this->v.begin();
	before = *tmp;
	tmp++;

	for (std::multiset<int>::iterator it = tmp ; it != this->v.end() ; it++) {
		cur = *it;
		if (min > cur - before)
			min = cur - before;
		before = cur;
	}
    return (min);
}

int _abs(int n) {
    return (n >= 0 ? n : -1 * n);
}

int Span::longestSpan(void) const {
	if (this->getN() == 0 || this->getN() == 1 || this->v.size() == 0 || this->v.size() == 1)
		throw std::runtime_error("stl's size is 0 or 1");
	int max = INT_MIN;
	for (std::multiset<int>::iterator it = this->v.begin() ; it != this->v.end() ; it++) {
		std::multiset<int>::iterator tmp = this->v.begin();
		for (std::multiset<int>::iterator it2 = tmp ; it2 != this->v.end() ; it2++) {
			//it = std::max_element(it, it2);
			if (max < _abs(*it - *it2))
				max = _abs(*it - *it2);
		}
	}
    return (max);
}

unsigned int Span::getN() const {
	return (this->N);
}