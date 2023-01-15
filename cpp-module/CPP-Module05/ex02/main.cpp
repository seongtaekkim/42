#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("seongtki", 1);
	Bureaucrat b2("staek", 150);

	Form* f1 = new ShrubberyCreationForm("s form name");
	Form* f2 = new RobotomyRequestForm("r form name");
	Form* f3 = new PresidentialPardonForm("p form name");

	std::cout << b1 << std::endl << b2 << std::endl << std::endl;

	std::cout << *f1 << std::endl;
	std::cout << *f3 << std::endl << std::endl;

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
