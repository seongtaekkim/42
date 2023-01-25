#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : name(""), signGrade(0), execGrade(0), isSigned(false) {}

Form::Form(const std::string &name, const int sGrade, const int eGrade)
	: name(name), signGrade(sGrade), execGrade(eGrade), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooHighException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& f) 
	: name(f.getName()), signGrade(f.getSignGrade()), execGrade(f.getExecGrade()), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooHighException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form(void) {}

Form& Form::operator=(const Form& f) {
	if (this == &f)
		return (*this);
	*(const_cast<std::string*>(&this->name)) = f.getName();
	*(const_cast<int*>(&this->signGrade)) = f.getSignGrade();
	*(const_cast<int*>(&this->execGrade)) = f.getExecGrade();
	this->isSigned = f.getIsSigned();
	return (*this);
}

const std::string& Form::getName() const {
	return (this->name);
}

const int& Form::getSignGrade() const {
	return (this->signGrade);
}

const int& Form::getExecGrade() const {
	return (this->execGrade);
}

const bool& Form::getIsSigned() const {
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("GradeTooHighException !!");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("GradeTooLowException !!");
}

std::ostream& operator << (std::ostream &out, const Form& f) {
	out << f.getName() << ", sign grade "
		<< f.getSignGrade() << ", exec grade "
		<< f.getExecGrade() << ", signed "
		<< std::boolalpha << f.getIsSigned();
    return (out);
}