#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* amateria[AMATERIA_SIZE];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& m);
	virtual ~MateriaSource(void);
	MateriaSource& operator=(const MateriaSource& m);
	const AMateria* getAMateria(int idx) const;
	void learnMateria(AMateria* a);
	AMateria* createMateria(const std::string& type);
};

#endif