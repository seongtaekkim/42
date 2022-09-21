
#ifndef SPAN_HPP
 #define SPAN_HPP
#include <vector>
#include <iostream>

class Span
{
private:
    unsigned int _n;
    std::vector<int> v;
public:
    Span(unsigned int n);
    ~Span();
    Span(const Span &s);
    Span & operator=(Span &s);
    void addNumber(int number);
    //void addNumber(T number);
    int shortestSpan();
    int longestSpan(); 
};

#endif