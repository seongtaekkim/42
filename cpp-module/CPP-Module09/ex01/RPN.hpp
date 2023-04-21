#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>

class RPN {
private:
    std::vector<std::size_t> _vec; 
public:
    RPN(void);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN(void);
};
#endif