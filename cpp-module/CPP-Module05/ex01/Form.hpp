#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private :
	const std::string 	name;
	const int			signGrade;
	const int			execGrade;
	bool				isSigned;
public :
	Form(void);
	Form(const std::string &name, const int sGrade, const int eGrade);
	Form(const Form& b);
	~Form(void);
	Form& operator=(const Form& f);
	const std::string& getName() const;
	const int& getSignGrade() const;
	const int& getExecGrade() const;
	const bool& getIsSigned() const;
	void beSigned(const Bureaucrat& b);
	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif