#include "BitcoinExchange.hpp"

#define DATE_SEPARATOR "-"
#define DB_PATH "data.csv"

Date::Date(void) {

}
// Date::Date(std::string data) {
//     valid(data);
// }
Date::~Date(void) {

}
#include <time.h>

bool Date::valid(std::string data) {
    // yyyy-mm-dd
    if (data.size() != 10) {
        return (0);
    }
    struct tm tm;

    memset(&tm, 0, sizeof(struct tm));
    strptime(data.c_str(), "%Y-%m-%d", &tm);
    if (tm.tm_year+1900 < 0)
        return (0);
    if (tm.tm_mon+1 > 12 || tm.tm_mon+1 < 1)
        return (0);
    if (tm.tm_mday > 31 ||  tm.tm_mday < 0) // 윤년
        return (0);
    // printf("%d/%d/%d %d:%d:%d\n",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
    //                                 tm.tm_hour, tm.tm_min, tm.tm_sec);
    return (1);
}


File::File(void) {
    this->fileName.append(DB_PATH);
}

File::File(char* name) {
    this->fileName.append(name);
}

File::DBType File::db(void) const {
    return this->_db;
}

	// try {
	// 	char *ptr = NULL;
    // 	*(const_cast<double*>(&this->dNum)) = std::strtod(raw.c_str(), &ptr);
    // 	if (*ptr && std::strcmp(ptr, "f") != 0)
    //   		throw std::bad_alloc();
	// 	std::cout << *this;
	// } catch(std::exception& e) {
	// 	if (raw.size() == 1) {
	// 		this->dNum = static_cast<char>(raw.c_str()[0]);
	// 		std::cout << *this;
	// 	}
	// 	else
	// 		std::cerr << "fail conversion !" << std::endl;
	// }

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int File::readFile(std::string sep)
{
	this->in.open(this->fileName.c_str());
	if (errno) // throw 로 변경1
		return (errno);
	std::string line;
	if (this->in.is_open())
	{
		while (std::getline(this->in, line))
		{
            std::size_t pos = line.find(sep, 0);
            if (pos == std::string::npos) {
                continue ;
            }
            if (Date::valid(trim(line.substr(0, pos)))) {
                char *ptr = NULL;
    	        double d = std::strtod(trim(line.substr(pos + 1)).c_str(), &ptr);
                float f = static_cast<float>(d);
                _db[line.substr(0, pos)] = f;
            }
		}
        this->in.close();
	}

    // DBType::iterator bit = _db.begin();
    // for (DBType::iterator i = bit ; i != _db.end() ; ++i) {
    //     std::cout << (*i).first << " : ";
    //     std::list<float>::iterator fit = i->second.begin();
    //     for (std::list<float>::iterator j = fit ; j != i->second.end() ; ++j) {
    //         std::cout << *j << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << " size : " << _db.size() << std::endl;
	return (0); 
}


int File::readFile2(std::string sep, File::DBType db) {
	this->in.open(this->fileName.c_str());
	if (errno) // throw 로 변경1
		return (errno);
	std::string line;
	if (this->in.is_open())
	{
		while (std::getline(this->in, line))
		{
            std::size_t pos = line.find(sep, 0);
            if (pos == std::string::npos) {
                continue ;
            }
            if (Date::valid(trim(line.substr(0, pos)))) {
                char *ptr = NULL;
    	        double d = std::strtod(trim(line.substr(pos + 1)).c_str(), &ptr);
                float f = static_cast<float>(d);
                if (f < 1000.0 && f > 0.0) {
                    // db 에 있있는  데이터보다 크크거거나  작작음음
                    // DBType::key_compare ret =  db.key_comp();
                    DBType::iterator bit = db.begin();
                    DBType::iterator i;
                    for (i = bit ; i != db.end() ; ++i ) {
                        if (i->first == trim(line.substr(0, pos))) {
                            break ;
                        } else if (i->first > trim(line.substr(0, pos))) {
                            --i;
                            break ;
                        }
                    }
                    std::cout << trim(line.substr(0, pos)) << " => " << i->second * f << std::endl;
                } else {
                    std::cerr << "Error : out bound ! " << std::endl;
                }
                
                    
            } else {
                std::cerr << "Error : invalid date format ! " << std::endl;
            }
		}
        this->in.close();
	}

    // DBType::iterator bit = _db.begin();
    // for (DBType::iterator i = bit ; i != _db.end() ; ++i) {
    //     std::cout << (*i).first << " : ";
    //     std::list<float>::iterator fit = i->second.begin();
    //     for (std::list<float>::iterator j = fit ; j != i->second.end() ; ++j) {
    //         std::cout << *j << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << " size : " << _db.size() << std::endl;
	return (0); 
}
