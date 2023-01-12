/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:08:07 by staek             #+#    #+#             */
/*   Updated: 2023/01/10 19:30:12 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int		size;
	int		oldestIndex;
public:
    PhoneBook();
	int getSize() const;
	void sizeUp();
	bool isFull() const;
	bool registContact(Contact contact);
	int getNextIndex() const;
	void printWithPadding(std::string str) const;
	void listAll() const;
	Contact getContact(int index) const;
};

#endif
