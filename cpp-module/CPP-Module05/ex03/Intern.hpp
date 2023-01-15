#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
	static Form* (*formFactory[3])(const std::string);
public:
	Intern(void);
	Intern(const Intern& i);
	~Intern(void);
	Intern& operator=(const Intern& i);
	Form* makeForm(const std::string& formName, const std::string& name);
	class NoMatchingTypeException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};
};


#endif