#include "ShrubberyCreationForm.hpp"
	
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, SSIGN_GRADE, SEXEC_GRADE ){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& p) : AForm(p) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& p) {
	return (*(dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(p)))));
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	valid_execute(executor);
	const std::string& filename = executor.getName() + "_shrubbery";
	std::ofstream ofs(filename.c_str());                        
	if (ofs.fail())
		throw AForm::FileException();
	ofs << "88                                      " << std::endl
	<< "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  "<< std::endl
	<< "88    88P'   \"Y8 a8P_____88 a8P_____88  "<< std::endl
	<< "88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  "<< std::endl
	<< "88,   88         \"8b,   ,aa \"8b,   ,aa  "<< std::endl
	<< "\"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'  " << std::endl;
}