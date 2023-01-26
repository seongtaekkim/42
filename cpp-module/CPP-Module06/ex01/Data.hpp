#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
private:
	std::string name;
	int			id;
	double		height;
	double		width;
public:
	Data(void);
	Data(const Data& d);
	Data(const std::string& name, int id, double height, double width);
	~Data(void);
	Data& operator=(const Data& d);
	const std::string& getName(void) const;
	const int& getId(void) const;
	const double& getHeight(void) const;
	const double& getWidth(void) const;
};

std::ostream& operator<<(std::ostream& o, const Data& ptr);
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
void showData(uintptr_t raw);

#endif