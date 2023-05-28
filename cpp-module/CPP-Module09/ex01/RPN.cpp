#include "RPN.hpp"

RPN::RPN(void) {}
RPN::~RPN(void) {}
	
bool RPN::allowedOp(char c) {
	if (c != '+' && c != '-' && c != '/' && c != '*')
		return false;
	else
		return true;
}

bool RPN::divideByZero(char *av, int i) {
	while (av[i]) {
		if (atoi(av + i) == 0 && av[i + 2] == '/')
			return true;
		i++;
	}
	return false;
}

void RPN::check(int ac, char *av, int i) {
	if (ac != 2)
		throw std::invalid_argument("Error");
	while (av[i]) {
		if ((!isdigit(av[i])) && allowedOp(av[i]) == false && av[i] != ' ')
			throw std::invalid_argument("Error");
		else
			i++;
	}
	if (divideByZero(av, 0) == true)
		throw std::invalid_argument("Error");
	return ;
}

int RPN::add(int nb1, int nb2) {
	return (nb1 + nb2);
}

int RPN::minus(int nb1, int nb2) {
	return (nb1 - nb2);
}

int	RPN::multiply(int nb1, int nb2) {
	return (nb1 * nb2);
}

int	RPN::divide(int nb1, int nb2) {
	return (nb1 / nb2);
}

void	RPN::run(char *av, int i) {
    
	std::stack<int>	data;
	int				tmp;
	int				j = 0;

	_set.insert(std::make_pair('+', &RPN::add));
	_set.insert(std::make_pair('-', &RPN::minus));
	_set.insert(std::make_pair('*', &RPN::multiply));
	_set.insert(std::make_pair('/', &RPN::divide));

	while (av[i]) {
		if (isdigit(av[i])) {
			data.push(atoi(av + i));
		} else if (allowedOp(av[i])) {
			if (data.empty())
				throw std::invalid_argument("Error");
			tmp = data.top();
			data.pop();
			for (FuncSetIter it = _set.begin() ; it != _set.end() ; ++it) {
				if (it->first == av[i]) {
					FuncPointer ptr = it->second;
					if (data.empty())
						throw std::invalid_argument("Error");
					tmp = (this->*ptr)(data.top(), tmp);
					break ;
				}
			}
			j = 0;
			data.pop();
			data.push(tmp);
		}
		i++;
	}
	if (data.size() > 1 || data.size() == 0)
		throw std::invalid_argument("Error");
	std::cout << GRNCOLOR <<  data.top() << ENDCOLOR << std::endl;
	return ;
}