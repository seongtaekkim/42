#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0 ; i < AMATERIA_SIZE ; i++)
		this->amateria[i] = NULL;
	std::cout << "Default Constructor MateriaSource " << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	for (int i = 0 ; i < AMATERIA_SIZE ; i++)
		this->amateria[i] = NULL;
	std::cout << "Copy Constructor MateriaSource" << std::endl;
	*this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	const AMateria* temp;
	if (this == &materiaSource)
		return (*this);
	std::cout << "Copy Assignment MateriaSource " << std::endl;
	for (int i = 0 ; i < AMATERIA_SIZE ; ++i)
	{
		if (this->amateria[i] != NULL)
		{
			delete this->amateria[i];
			this->amateria[i] = NULL;
		}
		temp = materiaSource.getAMateria(i);
		if (temp)
			this->amateria[i] = temp->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0 ; i < AMATERIA_SIZE ; i++)
	{
		if (this->amateria[i])
		{
			delete this->amateria[i];
			this->amateria[i] = NULL;
		}
	}
	std::cout << "Destruct MateriaSource" << std::endl;
}

const AMateria* MateriaSource::getAMateria(int idx) const
{
	return (this->amateria[idx]);
}

void MateriaSource::learnMateria(AMateria* amateria)
{
	if (amateria == NULL)
		return ;
	for (int i = 0 ; i < AMATERIA_SIZE ; i++)
	{
		if (this->amateria[i] == 0)
		{
			this->amateria[i] = amateria;
			std::cout << "learnMateria : " << this->amateria[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "learnMateria : " << amateria->getType() << " is FULL" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0 ; i < AMATERIA_SIZE ; ++i)
	{
		if (this->amateria[i] && this->amateria[i]->getType() == type)
		{
			std::cout << "createMateria Function on MateriaSource " << type << std::endl;
			return (this->amateria[i]->clone());
		}
	}
	std::cout << "createMateria Function on MateriaSource " << type << " Failed (Not Found)" << std::endl;
	return (NULL);
}