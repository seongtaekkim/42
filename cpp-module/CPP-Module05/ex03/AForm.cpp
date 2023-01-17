#include "AForm.hpp"

AForm::AForm(void) : signGrade(0), execGrade(0) {

}
AForm::AForm(const std::string &name, const int sGrade, const int eGrade)
	: name(name), signGrade(sGrade), execGrade(eGrade), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooLowException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooHighException();
}
AForm::AForm(const AForm& f) 
	: name(f.getName()), signGrade(f.getSignGrade()), execGrade(f.getExecGrade()), isSigned(false) {
	if (this->signGrade < 1 || this->execGrade < 1)
		throw GradeTooLowException();
	else if (this->signGrade > 150 || this->execGrade > 150)
		throw GradeTooHighException();
}
AForm::~AForm(void) {

}
AForm& AForm::operator=(const AForm& f) {
	if (this == &f)
		return (*this);
	*(const_cast<std::string*>(&this->name)) = f.getName();
	*(const_cast<int*>(&this->signGrade)) = f.getSignGrade();
	*(const_cast<int*>(&this->execGrade)) = f.getExecGrade();
	this->isSigned = f.getIsSigned();
	return (*this);
}
const std::string& AForm::getName() const {
	return (this->name);
}
const int& AForm::getSignGrade() const {
	return (this->signGrade);
}
const int& AForm::getExecGrade() const {
	return (this->execGrade);
}
const bool& AForm::getIsSigned() const {
	return (this->isSigned);
}
void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}
void AForm::valid_execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (this->execGrade < executor.getGrade())
		throw AForm::GradeTooLowException();
}
const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("GradeTooHighException !!");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("GradeTooLowException !!");
}
const char* AForm::NotSignedException::what(void) const throw() {
	return ("Not Signed Exception !!");
}
const char* AForm::FileException::what(void) const throw() {
	return ("File Exception !!");
}

std::ostream& operator << (std::ostream &out, const AForm& f) {
	out << f.getName() << ", signGrade " << f.getSignGrade() << ", execGrade "
		<< f.getExecGrade() << ", signed " << std::boolalpha << f.getIsSigned();
    return (out);
}