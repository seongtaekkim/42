#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(const T* t, std::size_t size, void (*f)(const T&)) {
	for (std::size_t i = 0 ; i < size ; i++) {
		(*f)(t[i]);
	}
}

template<typename T>
void print(const T &t) {
	std::cout << t << "	";
}

#endif