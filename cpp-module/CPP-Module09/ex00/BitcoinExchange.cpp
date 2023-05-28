#include "BitcoinExchange.hpp"

/**
 * @brief Date class
 * 
 */
const char* Date::DATEFORMAT = "%Y-%m-%d";

Date::Date(void) {}
Date::~Date(void) {}

bool Date::checkDate(int year, int month, int day){
	if ((month % 2 == 1) ) {
		if( month <= 7) {
			if ( day <= 0 || day > 31) return false; 
		} else {
			if ( day <= 0 || day > 30) return false; 
        }
	} else {
		if(month <= 6) {
			if (month == 2) {
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
                    if ( day<=0 || day>29)
                        return false;
                } else if ( day<=0 || day>28)
                    return false;
			}
			if (day<=0 || day>30)
                return false; 
		} else {
			if (day<=0 || day>31)
                return false; 
		}
	}	
    return (true);
}

bool Date::valid(std::string data) {
    if (data.size() != 10)
        return (0);
    
    struct tm tm;
    std::memset(&tm, 0, sizeof(struct tm));
    ::strptime(data.c_str(), Date::DATEFORMAT, &tm);
    if (checkDate(tm.tm_year, tm.tm_mon + 1, tm.tm_mday) == false)
        return (false);
    return (true);
}

/**
 * @brief File class
 * 
 */
const std::string File::WHITESPACE = " \n\r\t\f\v";
const std::string File::SEPARATOR_DATE = "-";
const std::string File::SEPARATOR_PIPE = "|";
const std::string File::SEPARATOR_COMMA = ",";
const std::string File::DB_PATH = "data.csv";

File::File(char* name) {
    this->_fileName = name;
    readDB(File::SEPARATOR_COMMA);
}

File::DBType File::db(void) const {
    return this->_db;
}
 
std::string File::ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(File::WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string File::rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(File::WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string File::trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int File::readDB(std::string sep) {
	this->_in.open(File::DB_PATH.c_str());
	std::string line;
    
	if (this->_in.is_open()) {
		while (std::getline(this->_in, line)) {
            std::size_t pos = line.find(sep, 0);
            if (pos == std::string::npos) {
                continue ;
            }
            if (Date::valid(this->trim(line.substr(0, pos)))) {
                char *ptr = NULL;
    	        double d = std::strtod(this->trim(line.substr(pos + 1)).c_str(), &ptr);
                if (*ptr)
      	            throw std::runtime_error("bad allocated value data : " + line);
                float f = static_cast<float>(d);
                _db[line.substr(0, pos)] = f;
            }
		}
        this->_in.close();
	} else {
        throw std::runtime_error("can't open file exception : " + File::DB_PATH);
    }
	return (0); 
}

int File::readFile(std::string sep) {
    if (this->_db.empty())
        throw std::runtime_error("can't find DB info");
	this->_in.open(this->_fileName.c_str());
	std::string line;
    char *ptr = NULL;
    int lineSize = 0;
    bool isFind = false;

	if (this->_in.is_open()) {
		while (std::getline(this->_in, line)) {
            lineSize++;
            std::size_t pos = line.find(sep, 0);
            if (pos == std::string::npos) {
                std::cout << REDCOLOR << "Error: bad input => " << line << ENDCOLOR << std::endl;
                continue ;
            }
            if (Date::valid(trim(line.substr(0, pos)))) {
    	        double d = std::strtod(trim(line.substr(pos + 1)).c_str(), &ptr);
                if (d > 1000.0) {
                    std::cout << REDCOLOR << "Error: too large a number." << ENDCOLOR << std::endl;
                    continue ;
                }
                if (d < 0.0) {
                    std::cout << REDCOLOR << "Error: not a positive number." << ENDCOLOR << std::endl;
                    continue ;
                }
                float f = static_cast<float>(d);
                DBType::iterator bit = this->_db.begin();
                DBType::iterator i;
                isFind = true;
                for (i = bit ; i != this->_db.end() ; ++i ) {
                    if (i->first == trim(line.substr(0, pos))) {
                        break ;
                    } else if (i->first > trim(line.substr(0, pos))) {
                        if (i == bit) {
                            std::cout << REDCOLOR << "Error : too old data ! : " << line << ENDCOLOR << std::endl;
                            isFind = false;
                            break ;
                        }
                        --i;
                        break ;
                    }
                }
                if (i == this->_db.end())
                    i--;
                if (isFind == true)
                    std::cout << GRNCOLOR <<  trim(line.substr(0, pos)) << " => " << f << " = " << i->second * f << ENDCOLOR << std::endl;

            } else {
                if (lineSize == 1)
                    continue;
                std::cout << REDCOLOR << "Error : invalid date format ! " << line << ENDCOLOR << std::endl;
            }
		}
        this->_in.close();
	} else {
        throw std::runtime_error("can't open file exception : " + this->_fileName);
    }
	return (0); 
}
