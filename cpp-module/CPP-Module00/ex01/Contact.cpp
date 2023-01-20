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
	std::cout << "index : " << this->index << std::endl;	
	std::cout << "firstName : " << this->firstName << std::endl;	
	std::cout << "lastName : " << this->lastName << std::endl;	
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phoneNumber : " << this->phoneNumber << std::endl;
	std::cout << "darkestSecret : " << this->darkestSecret << std::endl;
}
void Contact::setIndex(int index) {
	this->index = index;
}