#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];
	int		size;
	int		oldestIndex;
	void sizeUp();
	bool isFull() const;
public:
    PhoneBook();
	int getSize() const;
	int getNextIndex() const;
	bool registContact(Contact contact);
	void printWithPadding(std::string str) const;
	void listAll() const;
	Contact getContact(int index) const;
};

#endif
