#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private :
	const std::string 	name;
	const int			signGrade;
	const int			execGrade;
	bool				isSigned;
protected :
	AForm(void);
	AForm(const std::string &name, const int sGrade, const int eGrade);
public :
	AForm(const AForm& b);
	virtual ~AForm(void);
	AForm& operator=(const AForm& f);
	const std::string& getName() const;
	const int& getSignGrade() const;
	const int& getExecGrade() const;
	const bool& getIsSigned() const;
	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& b) const = 0;
	void valid_execute(const Bureaucrat& executor) const;
	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class NotSignedException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class FileException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif