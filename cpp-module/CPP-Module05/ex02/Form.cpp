#include "Form.hpp"

Form::Form(void) : signGrade(0), execGrade(0) {

}
Form::Form(const std::string &name, const int sGrade, const int eGrade)
	: name(name), signGrade(sGrade), execGrade(eGrade), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooLowException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooHighException();
}
Form::Form(const Form& f) 
	: name(f.getName()), signGrade(f.getSignGrade()), execGrade(f.getExecGrade()), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooLowException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooHighException();
}
Form::~Form(void) {

}
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
void Form::valid_execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false)
		throw Form::NotSignedException();
	else if (this->execGrade < executor.getGrade())
		throw Form::GradeTooLowException();
}
const char* Form::GradeTooHighException::what(void) const throw() {
	return ("GradeTooHighException !!");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("GradeTooLowException !!");
}
const char* Form::NotSignedException::what(void) const throw() {
	return ("Not Signed Exception !!");
}
const char* Form::FileException::what(void) const throw() {
	return ("File Exception !!");
}

std::ostream& operator << (std::ostream &out, const Form& f) {
	out << f.getName() << ", signGrade " << f.getSignGrade() << ", execGrade "
		<< f.getExecGrade() << ", signed " << std::boolalpha << f.getIsSigned();
    return (out);
}