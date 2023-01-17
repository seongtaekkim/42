#include "RobotomyRequestForm.hpp"
	
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm() {

}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, RSIGN_GRADE, REXEC_GRADE ) {

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& p)
	: AForm(p) {

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& p) {
	return (*(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(p)))));
}
RobotomyRequestForm::~RobotomyRequestForm(void) { }
AForm* RobotomyRequestForm::selfFactory(const std::string name) {
	return (new RobotomyRequestForm(name));
}
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	valid_execute(executor);
   	std::cout << "drill...... drill....." << std::endl;
	struct timeval t;
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	if (rand() % 2 == 0) {
		std::cout << this->getName() << " has been robotomized successfully 50% of the time" << std::endl;
	} else {
		std::cout << this->getName() << " that the robotomy failed" << std::endl;
	}
}