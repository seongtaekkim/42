#include "Data.hpp"

Data::Data(void)
	: name(""), id(0), height(0.0), width(0.0) {}

Data::Data(const std::string& name, int id, double height, double width)
	: name(name), id(id), height(height), width(width) {}

Data::Data(const Data& d) {
	*this = d;
}

Data::~Data(void) {}

Data& Data::operator=(const Data& d) {
	if (this == &d)
		return (*this);
	this->name = d.getName();
	this->id = d.getId();
	this->height = d.getHeight();
	this->width = d.getWidth();
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Data& d) {
	out << "address : " << &d << std::endl
		<< "name : " << d.getName() << std::endl
		<< "id : " << d.getId() << std::endl
		<< "height : " << d.getHeight() << std::endl
		<< "width : " << d.getWidth() << std::endl << std::endl;
	return (out);
}

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

const std::string& Data::getName(void) const {
	return (this->name);
}

const int& Data::getId(void) const {
	return (this->id);
}

const double& Data::getHeight(void) const {
	return (this->height);
}

const double& Data::getWidth(void) const {
	return (this->width);
}

void showData(uintptr_t raw) {
	Data *d = deserialize(raw);
	if (!d)
		return ;
	std::cout << "address : " << d << std::endl
		<< "name : " << d->getName() << std::endl
		<< "id : " << d->getId() << std::endl
		<< "height : " << d->getHeight() << std::endl
		<< "width : " << d->getWidth() << std::endl << std::endl;
}