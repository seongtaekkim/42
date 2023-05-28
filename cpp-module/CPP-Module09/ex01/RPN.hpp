#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <stack>
#include <cstdlib>
#include <set>

#define REDCOLOR "\033[1;31m"
#define GRNCOLOR "\033[1;32m"
#define ENDCOLOR "\033[0m"

struct comp {
    template<typename T>
    bool operator()(const T &l, const T &r) const {
        (void)l;
        (void)r;
       return (true);
    }
};

class RPN {
public:
	typedef int (RPN::*FuncPointer)(int, int);
	typedef std::set<std::pair<char, FuncPointer>, comp > FuncSet;
	typedef FuncSet::iterator FuncSetIter;
private:
    RPN& operator=(const RPN& other);
    RPN(const RPN& other);
	FuncSetIter						_pos;
	FuncSet							_set;
public:
    RPN(void);
    ~RPN(void);
    bool allowedOp(char c);
    void check(int ac, char *av, int i);
    void run(char *av, int i);
    bool divideByZero(char *av, int i);
    int	add(int n1, int n2);
    int	minus(int n1, int n2);
    int	multiply(int n1, int n2);
    int	divide(int n1, int n2);
};



#endif