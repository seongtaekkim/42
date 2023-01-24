#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure& c);
	virtual ~Cure(void);
	Cure& operator=(const Cure& c);
	AMateria* clone(void) const;
	virtual void use(const ICharacter& ic);
};

#endif