#ifndef CAST_HPP
# define CAST_HPP

#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#define C_ND		"Non displayable"
#define C_NP		"impossible"


class Cast {
private:
	const std::string raw;
	double dNum;
	Cast(void);
	Cast& operator=(const Cast& c);
public:
	explicit Cast(const std::string& input);
	Cast(const Cast& c);
	~Cast(void);

	char asChar(void) const;
	int asInt(void) const;
	float asFloat(void) const;
	double asDouble(void) const;

	//bool getError(void) const;
	const double& getDNum(void) const;
	const std::string& getRaw(void) const;

	// class NumberException : public std::exception
	// {
	// 	private:
	// 		const std::string _message;
	// 		const size_t _position;

	// 	public:
	// 		NumberException(void);
	// 		NumberException(std::string message);
	// 		NumberException(std::string message, size_t position);
	// 		NumberException(const NumberException &other);

	// 		virtual ~NumberException(void) throw ();

	// 		NumberException& operator=(const NumberException &other);

	// 		virtual const char* what() const throw ();

	// 		const std::string &message() const;
	// 		const size_t &position() const;

	// 		static NumberException invalidFormat(std::string reason);
	// 		static NumberException invalidFormat(std::string reason, size_t position);
	// 		static NumberException impossible();
	// 		static NumberException nonDisplayable();
	// };
	
	class ConvertException : public std::exception {
		public:
			const char* what(void) const throw();
			static ConvertException impossible();
	};

};
std::ostream& operator<<(std::ostream& out, const Cast& c);

#endif