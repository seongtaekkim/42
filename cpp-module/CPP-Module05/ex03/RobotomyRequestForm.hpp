#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <sys/time.h>
#include "AForm.hpp"

#define RSIGN_GRADE 72
#define REXEC_GRADE 45

class RobotomyRequestForm : public AForm {
private:
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& p);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& p);
	~RobotomyRequestForm(void);
	virtual void execute(const Bureaucrat& executor) const;
	static AForm* selfFactory(const std::string name);
};

#endif