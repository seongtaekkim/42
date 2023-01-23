#include "Replace.hpp"

Replace::Replace(const std::string fileName
	, const std::string s1, const std::string s2)
	: fileName(fileName), s1(s1), s2(s2) {}

int Replace::readFile(std::string& dest)
{
	this->in.open(this->fileName.c_str());
	if (errno)
		return (errno);
	std::string line;
	if (this->in.is_open())
	{
		while (std::getline(this->in, line))
		{
			dest.append(line);
			if (!this->in.eof())
				dest.append("\n");
		}
	}
	return (0); 
}

int Replace::saveFile()
{
	std::string outfile = this->fileName + ".replace";
	this->of.open(outfile.c_str());
	if (errno)
		return (errno);
	return (0);
}

int Replace::replace()
{
	std::size_t pos = 0;
	std::size_t ret = 0;
	std::string dest;

	if (this->s1.size() == 0)
	{
		errno = EINVAL;
		return (errno);
	}

	errno = readFile(dest);
	if (errno != 0)
		return (errno);
	while(true)
	{
		ret = dest.find(s1, pos);
		if(ret == std::string::npos)
		{
			break ;
		}
		else
		{
			pos = ret;
			dest.erase(pos, s1.size());
			dest.insert(pos, s2);
			pos += s2.size();
		}
	}
	errno = saveFile();
	if (errno != 0)
		return (errno);
	this->of << dest;
	if (in.is_open())
  		in.close();
	if (of.is_open())
  		of.close();
	return (0);
}