#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PSIGN_GRADE 25
#define PEXEC_GRADE 5

class PresidentialPardonForm : public AForm {
private:
	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& p);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
	~PresidentialPardonForm(void);
	virtual void execute(const Bureaucrat& executor) const;
	static AForm* selfFactory(const std::string name);
};

#endif