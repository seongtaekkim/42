#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

#define SSIGN_GRADE 145
#define SEXEC_GRADE 137

class ShrubberyCreationForm : public Form {
private:
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& p);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& p);
	~ShrubberyCreationForm(void);
	virtual void execute(const Bureaucrat& executor) const;
	static Form* selfFactory(const std::string name);
};

#endif