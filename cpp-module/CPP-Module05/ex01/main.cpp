#include "Form.hpp"

void createFormTest(const std::string& name,
			const int& signGrade,
			const int& execGrade) {
	try {
		Form f(name, signGrade, execGrade);
		std::cout << f << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	Bureaucrat seongtki("seongtki", 30);
	Bureaucrat staek("staek", 50);
	Form form1("form1", 120, 50);
	Form form2("form2", 30, 30);

	std::cout << seongtki << std::endl
			  << staek << std::endl;
	std::cout << std::endl;
	std::cout << form1 << std::endl
			  << form2 << std::endl;
	std::cout << std::endl;

	seongtki.signForm(form1);
	staek.signForm(form1);
	seongtki.signForm(form2);
	staek.signForm(form2);
	std::cout << std::endl;

	createFormTest("testform1", 0, 10);
	createFormTest("testform2", 10, 0);
	createFormTest("testform3", 151, 10);
	createFormTest("testform4", 10, 151);
	return (0);
}