#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
private:
	const std::string 	name;
	int					grade;
	Bureaucrat(void);
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& b);
	const std::string& getName() const;
	const int& getGrade() const;
	void increment();
	void decrement();
	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif