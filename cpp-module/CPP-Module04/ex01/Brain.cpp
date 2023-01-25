#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
	for (int i =0 ; i < 100 ; i++) {
		this->ideas[i] = "brain's ideas";
	}
}

Brain::Brain(const Brain &b) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = b;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator = (const Brain& b) {
    std::cout << "Brain Copy Assignment operator called" << std::endl;
    if (this == &b)
        return (*this);
    return (*this);
}

std::string Brain::getIdeas(const int& i) const {
	return (ideas[i]);
}

std::ostream& operator<< (std::ostream& out, const Brain& b) {
    for (int i = 0 ; i < 100 ; i++)
        out << b.getIdeas(i) << " ";
    return (out);
}