#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
	*this = b;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	if (this == &b)
		return (*this);
	this->grade = b.getGrade();
	*(const_cast<std::string*>(&name)) = b.getName();
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return (this->name);
}

const int& Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::increment() {
	if (this->grade == 1)
		throw GradeTooHighException();
	(this->grade)--;
}

void Bureaucrat::decrement() {
	if (this->grade == 150)
		throw GradeTooLowException();
	(this->grade)++;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("GradeTooHighException !!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("GradeTooLowException !!");
}