#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#define AMATERIA_SIZE 4

class ICharacter;

class AMateria
{
protected:
	std::string type;
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& a);
public:
	virtual ~AMateria(void);
	AMateria& operator=(const AMateria& a);
	const std::string& getType(void) const;
	virtual AMateria* clone(void) const = 0;
	virtual void use(const ICharacter& i);
};

#endif