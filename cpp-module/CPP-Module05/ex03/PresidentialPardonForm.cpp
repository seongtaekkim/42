
#include "PresidentialPardonForm.hpp"
	
PresidentialPardonForm::PresidentialPardonForm(void) : Form() {
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form(target, PSIGN_GRADE, PEXEC_GRADE ){
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
	: Form(p) {
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p) {
	return (*(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(p)))));
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
Form* PresidentialPardonForm::selfFactory(const std::string name) {
	return (new PresidentialPardonForm(name));
}
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	valid_execute(executor);
	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}