#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
//#include <iomanip>
#include <iostream>
#include "Character.hpp"

#define W_SIZE		40
#define AM_SIZE		4

class ICharacter; 

class AMateria
{
protected:
	std::string _type;

public:

	AMateria(void);
	AMateria(const AMateria& am);
	AMateria(const std::string& type);
	virtual ~AMateria(void);
	AMateria& operator=(const AMateria& am);
	const std::string& getType(void) const;
	virtual AMateria* clone(void) const = 0;
	virtual void use(const ICharacter& ic);
};

#endif