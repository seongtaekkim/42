
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat b1("seongtki", 1);
	Bureaucrat b2("staek", 150);
 
	AForm* f1 = intern.makeForm("ShrubberyCreationForm", "SSSSName");
	AForm* f2 = intern.makeForm("RobotomyRequestForm", "RRRRName");
	AForm* f3 = intern.makeForm("PresidentialPardonForm", "PPPPName");
	intern.makeForm("Wrong", "Wrong");
	std::cout << std::endl;

	std::cout << b1 << std::endl << b2 << std::endl;
	std::cout << std::endl;

	std::cout << *f1 << std::endl
		<< *f2 << std::endl
		<< *f3 << std::endl;
	std::cout << std::endl;

	b2.signForm(*f1);
	b2.signForm(*f2);
	b2.signForm(*f3);
	std::cout << std::endl;

	b1.signForm(*f1);
	b1.signForm(*f2);
	b1.signForm(*f3);
	std::cout << std::endl;

	b2.executeForm(*f1);
	b2.executeForm(*f2);
	b2.executeForm(*f3);
	std::cout << std::endl;

	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return (0);
}