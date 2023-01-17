
#include "PresidentialPardonForm.hpp"
	
PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, PSIGN_GRADE, PEXEC_GRADE ){
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
	: AForm(p) {
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p) {
	return (*(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(p)))));
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
AForm* PresidentialPardonForm::selfFactory(const std::string name) {
	return (new PresidentialPardonForm(name));
}
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	valid_execute(executor);
	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}