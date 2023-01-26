#ifndef CAST_HPP
# define CAST_HPP

#include <cmath>
#include <iostream>

#define D_NON_DESPLAYABLE	"Non displayable"
#define D_IMPOSSIBLE		"impossible"

class Cast {
private:
	const std::string raw;
	double dNum;
	Cast(void);
	Cast& operator=(const Cast& c);
public:
	Cast(const std::string& input);
	Cast(const Cast& c);
	~Cast(void);
	char asChar(void) const;
	int asInt(void) const;
	float asFloat(void) const;
	double asDouble(void) const;
	const double& getDNum(void) const;
	const std::string& getRaw(void) const;
};

std::ostream& operator<<(std::ostream& out, const Cast& c);

#endif