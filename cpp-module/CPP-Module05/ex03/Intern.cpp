#include "Intern.hpp"

Intern::Intern(void) {

}
Intern::Intern(const Intern& i) {
	*this = i;
}
Intern::~Intern(void) {}
Intern& Intern::operator=(const Intern& i) {
	if (this == &i)
		return (*this);
	static_cast<void>(i);
	return (*this);
}
AForm* (*Intern::formFactory[3])(const std::string) =
{
	&ShrubberyCreationForm::selfFactory
	, &RobotomyRequestForm::selfFactory
	, &PresidentialPardonForm::selfFactory
};
AForm* Intern::makeForm(const std::string& formName, const std::string& name) {
	std::string typeList[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	try
	{
		for (int i = 0 ; i < 3 ; ++i)
		{
			if (typeList[i] == formName)
			{
				std::cout << "Intern creates " << name << std::endl;
				return ((*Intern::formFactory[i])(name));
			}
		}
		throw NoMatchingTypeException();
	}
	catch (std::exception& e)
	{
		std::cerr << "Intern can't create " << name
			<< " because " << e.what() << std::endl;
		return (NULL);
	}
}
const char* Intern::NoMatchingTypeException::what(void) const throw()
{
	return ("NoMatchingTypeException !!");
}