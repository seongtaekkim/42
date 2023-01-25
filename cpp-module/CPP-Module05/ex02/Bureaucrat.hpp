#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
class AForm;
class Bureaucrat {
private:
	const std::string 	name;
	int					grade;
	Bureaucrat(void);
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& b);
	const std::string& getName() const;
	const int& getGrade() const;
	void increment();
	void decrement();
	void signForm(const AForm& f) const;
	void executeForm(AForm const & form);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif