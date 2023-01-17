#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {

}
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: name(name) {
	if (grade < 1)
		throw AForm::GradeTooLowException();
	else if (grade > 150)
		throw AForm::GradeTooHighException();
	else
		this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& b) {
	*this = b;
}
Bureaucrat::~Bureaucrat(void) {

}
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
	if (this->grade == 150)
		throw AForm::GradeTooHighException();
	(this->grade)++;
}
void Bureaucrat::decrement() {
	if (this->grade == 1)
		throw AForm::GradeTooLowException();
	(this->grade)--;
}
void Bureaucrat::signForm(const AForm& f) const {
	try {
		(*const_cast<AForm*>(&f)).beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cerr << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cerr  << this->name << " cannot execute "
			<< form.getName() << " because "
			<< e.what() << std::endl;
	}
}
std::ostream& operator << (std::ostream &out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}