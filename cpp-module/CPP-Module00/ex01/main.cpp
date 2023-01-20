#include "PhoneBook.hpp"

bool getlineContact(std::string str, std::string &attr) {
	while (1) {
		std::cout << str << " : ";
		std::getline(std::cin, attr);
		if (std::cin.eof()) {
			std::cout << "EXIT" << std::endl;
			return (false);
		}
		if (attr == "")
			std::cout << "input your info" << std::endl;
		else
			break ;
	}
	return (true);
}

int	main(void) {
	std::string command;
	PhoneBook	phoneBook;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string	index;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			if (!getlineContact("firstName", firstName))
				break ;
			if (!getlineContact("lastName", lastName))
				break ;
			if (!getlineContact("nickname", nickname))
				break ;
			if (!getlineContact("phoneNumber", phoneNumber))
				break ;
			if (!getlineContact("darkestSecret", darkestSecret))
				break ;
			phoneBook.registContact(
				Contact(phoneBook.getNextIndex(), firstName, lastName, nickname, phoneNumber, darkestSecret));
		}
		if (command == "SEARCH")
		{
			phoneBook.listAll();
			if (!getlineContact("index", index))
				break ;
			if (index.size() > 1 || index.size() == 0) {
				std::cerr << "Please enter a value between 0 and " << (index.size() - 1) << std::endl;
				continue;
			}
			int d = static_cast<int>(std::strtod(index.c_str(), NULL));
			if (d > (phoneBook.getSize() -1) || d < 0) {
				std::cerr << "out of range !" << std::endl;
				continue;
			}
			phoneBook.getContact(d).toString();
		}
		else if (command == "EXIT")	
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
	}
	return (0);
}
