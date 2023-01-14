#include "MateriaSource.hpp"

const AMateria* MateriaSource::getAMateria(int idx) const
{
	return (_am[idx]);
}

void MateriaSource::learnMateria(AMateria* am)
{
	if (!am)
		return ;
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (!_am[i])
		{
			_am[i] = am;
			std::cout << "learnMateria Function on MateriaSource " << am->getType() << std::endl;
			return ;
		}
	}
	std::cout << "learnMateria Function on MateriaSource" << am->getType() << " Failed (FULL)" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i] && _am[i]->getType() == type)
		{
			std::cout << "createMateria Function on MateriaSource " << type << std::endl;
			return (_am[i]->clone());
		}
	}
	std::cout << "createMateria Function on MateriaSource " << type << " Failed (Not Found)" << std::endl;
	return (NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	const AMateria* temp;

	if (this != &ms)
	{
		for (int i = 0 ; i < AM_SIZE ; ++i)
		{
			if (_am[i])
			{
				delete _am[i];
				_am[i] = NULL;
			}
			temp = ms.getAMateria(i);
			if (temp)
				_am[i] = temp->clone();
		}
	}
	std::cout << "Assignation on MateriaSource " << std::endl;
	return (*this);
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
		_am[i] = NULL;
	std::cout << "Default Constructor on MateriaSource " << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	const AMateria* temp;

	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		temp = ms.getAMateria(i);
		if (temp)
			_am[i] = temp->clone();
	}
	std::cout << "Copy Constructor on MateriaSource" << " ]" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
	}
	std::cout << "Destructor on MateriaSource" << " ]" << std::endl;
}