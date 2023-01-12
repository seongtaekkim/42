/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:51:10 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/10 19:19:21 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    : size(0), oldestIndex(0) {}
void PhoneBook::sizeUp() {
	if (this->size < 8)
		this->size += 1;
}
bool PhoneBook::isFull() const {
	if (this->size == 8)
		return (true);
	return (false);
}
int PhoneBook::getSize() const {
    return (this->size);
}
bool PhoneBook::registContact(Contact c) {
	if (this->size == 8)
	{
		this->contact[this->oldestIndex] = c;
		this->contact[this->oldestIndex].setIndex(this->oldestIndex);
		this->oldestIndex %= 8;
		this->oldestIndex++;
	}
	this->contact[c.getIndex()] = c;
	this->sizeUp();
	return (true);
}
int PhoneBook::getNextIndex() const {
	if (this->isFull())
		return (this->size - 1);
	return (size);
}
void PhoneBook::printWithPadding(std::string str) const {
	int padding = 10 - str.length();
	for (int i = 0 ; i < padding ; i++)
		std::cout << " ";
	if (padding < 0 ) {
		str.resize(10);
		str.at(9) = '.';
	}
	std::cout << str << "|";
}

Contact PhoneBook::getContact(int index) const {
	return (this->contact[index]);
}

void PhoneBook::listAll() const {
	for (int i = 0 ; i < this->size ; i++) {
		std::cout << this->contact[i].getIndex() << "|";
		printWithPadding(this->contact[i].getFirstName());
		printWithPadding(this->contact[i].getLastName());
		printWithPadding(this->contact[i].getNickname());
		std::cout << std::endl;
	}
};