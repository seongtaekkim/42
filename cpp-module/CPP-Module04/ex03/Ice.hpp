#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice& i);
	virtual ~Ice(void);
	Ice& operator=(const Ice& i);
	AMateria* clone(void) const;
	virtual void use(const ICharacter& ic);
};

#endif