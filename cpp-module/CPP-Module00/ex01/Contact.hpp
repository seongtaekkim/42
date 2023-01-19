/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staek <staek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:12:44 by staek             #+#    #+#             */
/*   Updated: 2023/01/10 19:29:20 by staek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	int			index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
    Contact();
    Contact(int index, std::string &firstName, std::string &lastName,
		std::string &nickname, std::string &phoneNumber, std::string &darkestSecret);
	int	getIndex() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	void toString();
	void setIndex(int index);
};

#endif