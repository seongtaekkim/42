#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
private:
    T*				m_data;
    unsigned int	m_length;
public:
    Array() : m_length(0), m_data(NULL) {}
    Array(unsigned int length)
        :  m_data(new T [length]), m_length(length) {}
    Array(const Array& a) {
		this->m_length = a.size();
		if (this->m_length > 0)
			this->m_data = new T [this->m_length];
		for (unsigned int i = 0 ; i < this->m_length ; i++) {
			this->m_data[i] = a.m_data[i];
		}
	}

    ~Array() {
        reset();
	}

	Array& operator=(const Array& a)
	{
		if (this == &a)
			return (*this);
		if (this->m_length > 0)
			reset();
		this->m_length = a.size();
		if (this->m_length > 0)
			this->m_data = new T[this->m_length];
		for (unsigned int i = 0 ; i < this->m_length ; i++)
			this->m_data[i] = a[i];
		return (*this);
	}

    void reset() {
        delete[] this->m_data;
        this->m_data = NULL;
        this->m_length = 0;
    }

    T& operator[] (unsigned int index) {
		if (index >= this->m_length) {
			throw OutOfRange();
		}
        return (this->m_data[index]);
    }

	const T& operator[] (unsigned int index) const {
		if (index >= this->m_length) {
			throw OutOfRange();
		}
		return (this->m_data[index]);
	}

    unsigned int size() const {
        return (this->m_length);
    }

	class OutOfRange : public std::exception {
		public:
			const char* what(void) const throw() {
				return ("out of range !!");
			}
	};
};

#endif