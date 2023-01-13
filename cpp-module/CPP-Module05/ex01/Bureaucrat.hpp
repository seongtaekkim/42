#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
class Form;
class Bureaucrat {
private:
	const std::string 	name;
	int					grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& b);
	const std::string& getName() const;
	const int& getGrade() const;
	void increment();
	void decrement();
	void signForm(const Form& f) const;
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif