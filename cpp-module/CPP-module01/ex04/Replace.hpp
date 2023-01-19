#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
private:
    const std::string fileName;
	const std::string s1;
	const std::string s2;
	std::ifstream in;
	std::ofstream of;
	Replace(void);
public:
	Replace(const std::string fileName
		, const std::string s1, const std::string s2);
	int readFile(std::string &dest);
	int replace();
	int saveFile();
};

#endif