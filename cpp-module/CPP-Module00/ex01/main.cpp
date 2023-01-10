/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:21:52 by staek             #+#    #+#             */
/*   Updated: 2023/01/10 19:29:02 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>


bool getlineContact(std::string str, std::string &attr) {
	std::cout << str << " : ";
	std::getline(std::cin, attr);
	if (std::cin.eof())
	{
		std::cout << "EXIT" << std::endl;
		return (false);
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
			if (index.size() > 1 || index.size() == 0)
				continue;
			std::cout << (char)index[0] << std::endl;
			int d = index.at(0) - '0';
			if (d > (phoneBook.getSize() -1) || d < 0)
				continue;
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
