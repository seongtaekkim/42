#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria* a) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif