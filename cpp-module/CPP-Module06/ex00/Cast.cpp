#include "Cast.hpp"

Cast::Cast(const std::string& raw) : raw(raw) {
	try {
		this->dNum  = std::stod(raw);
		std::cout << *this;
	} catch(std::exception& e) {
		if (raw.size() == 1) {
			this->dNum = static_cast<char>(raw.c_str()[0]);
			std::cout << *this;
		}
		else
			std::cerr << "fail conversion !" << std::endl;
	}
}

Cast::Cast(const Cast& c) : raw(c.getRaw()), dNum(c.getDNum()) {}

Cast::~Cast(void) {}

Cast& Cast::operator=(const Cast& c) {
	if (this == &c)
		return (*this);
	return (*this);
}

char Cast::asChar(void) const {
	char c = static_cast<char>(this->dNum);
	return (c);
}

int Cast::asInt(void) const {
	int i = static_cast<int>(this->dNum);
	return (i);
}

float Cast::asFloat(void) const {
	float f = static_cast<float>(this->dNum);
	return (f);
}
 
double Cast::asDouble(void) const {
	double d = static_cast<double>(this->dNum);
	return (d);
}

const double& Cast::getDNum(void) const {
	return (this->dNum);
}

const std::string& Cast::getRaw(void) const {
	return (this->raw);
}

std::ostream& operator<<(std::ostream& out, const Cast& c) {

	out << "char: ";
	if (std::isnan(c.getDNum()) || std::isinf(c.getDNum()))
		out << D_IMPOSSIBLE << std::endl;
	else if (std::isprint(c.asChar()))
		out << "'" << c.asChar() << "'" << std::endl;
	else
		out << D_NON_DESPLAYABLE << std::endl;
	
	out << "int: ";
	if (std::isnan(c.getDNum()) || std::isinf(c.getDNum()))
		out << D_IMPOSSIBLE << std::endl;
	else
		out << c.asInt() << std::endl;

	if (std::isnan(c.getDNum()) || std::isinf(c.getDNum()))
	{
		out << "float: " << std::showpos << c.asFloat() << "f" << std::endl;
		out << "double: " << std::showpos << c.asDouble() << std::endl;
	}
	else {
		if (c.asFloat() == static_cast<int>(c.asFloat()))
			out << "float: " << c.asFloat() << ".0f" << std::endl;
		else
			out << "float: " << c.asFloat() << "f" << std::endl;
		if (c.asDouble() == static_cast<int>(c.asDouble()))
			out << "double: " << c.asDouble() << ".0" << std::endl;
		else
			out << "double: " << c.asDouble() << std::endl;
	}
	return (out);
}