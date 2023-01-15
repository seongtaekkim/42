#include "ShrubberyCreationForm.hpp"
	
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(target, SSIGN_GRADE, SEXEC_GRADE ){

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& p)
	: Form(p) {
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& p) {
	return (*(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(p)))));
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) { }
Form* ShrubberyCreationForm::selfFactory(const std::string name) {
	return (new ShrubberyCreationForm(name));
}
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	valid_execute(executor);
	const std::string& filename = executor.getName() + "_shrubbery";
	std::ofstream ofs(filename.c_str());                        
	if (ofs.fail())
		throw Form::FileException();
	ofs << "88                                      " << std::endl
	<< "MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  "<< std::endl
	<< "88    88P'   \"Y8 a8P_____88 a8P_____88  "<< std::endl
	<< "88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  "<< std::endl
	<< "88,   88         \"8b,   ,aa \"8b,   ,aa  "<< std::endl
	<< "\"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'  " << std::endl;
}