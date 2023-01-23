#include "Contact.hpp"

Contact::Contact() {};

Contact::Contact(int index, std::string &firstName, std::string &lastName,
		std::string &nickname, std::string &phoneNumber, std::string &darkestSecret)
    : index(index), firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret)
{}

int Contact::getIndex() const {
    return (this->index);
}

std::string Contact::getFirstName() const {
	return (this->firstName);
}

std::string Contact::getLastName() const {
	return (this->lastName);
}

std::string Contact::getNickname() const {
	return (this->nickname);
}

void Contact::toString() {
	std::cout << "firstName : " << this->firstName << std::endl
			<< "lastName : " << this->lastName << std::endl
			<< "nickname : " << this->nickname << std::endl
			<< "phoneNumber : " << this->phoneNumber << std::endl
			<< "darkestSecret : " << this->darkestSecret << std::endl;
}
void Contact::setIndex(int index) {
	this->index = index;
}