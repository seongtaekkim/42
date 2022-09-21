#include "Span.hpp"

Span::Span(unsigned int n)
    : _n(n) 
{
    v.push_back(this->_n);
}

Span::~Span() {}

Span::Span(const Span &s)
{
    this->_n = s._n;
    this->v = s.v; // copy assignment ?
}

Span & Span::operator=(Span &s)
{
    this->_n = s._n;
    this->v = s.v; // copy assignment ?
    return (*this);
}

void Span::addNumber(int number)
{
    this->v.push_back(number);
}

int Span::shortestSpan()
{
    return (1);
}

int _abs(int n)
{
    return (n >= 0 ? n : -1 * n);
}

int Span::longestSpan()
{
    return (1);
}

