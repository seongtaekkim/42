#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _am[AM_SIZE];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& ms);
	virtual ~MateriaSource(void);
	MateriaSource& operator=(const MateriaSource& ms);
	const AMateria* getAMateria(int idx) const;
	void learnMateria(AMateria* am);
	AMateria* createMateria(const std::string& type);
};

#endif