#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class AMateria;
class Character : public ICharacter {
public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& c);
	virtual ~Character(void);
	Character& operator=(const Character& c);
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif