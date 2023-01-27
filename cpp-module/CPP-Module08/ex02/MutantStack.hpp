#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack<T>& m) : std::stack<T>(m) {}
	~MutantStack(void) {}
	MutantStack<T>& operator=(const MutantStack<T>& m) {
		if (this == &m)
			return (*this);
		std::stack<T>::operator= (m);
		return (*this);
	}

	iterator begin(void) {
		return (this->c.begin());
	}
	iterator end(void) {
		return (this->c.end());
	}
	reverse_iterator rbegin(void) {
		return (this->c.rbegin());
	}
	reverse_iterator rend(void) {
		return (this->c.rend());
	}
	const_iterator cbegin(void) const {
		return (this->c.begin());
	}
	const_iterator cend(void) const {
		return (this->c.end());
	}
	const_reverse_iterator crbegin(void) const {
		return (this->c.rbegin());
	}
	const_reverse_iterator crend(void) const {
		return (this->c.rend());
	}
};

#endif