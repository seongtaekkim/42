#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <time.h>

#define REDCOLOR "\033[1;31m"
#define GRNCOLOR "\033[1;32m"
#define YELCOLOR "\033[1;33m"
#define BLUECOLOR "\033[1;34m"
#define MAGCOLOR "\033[1;35m"
#define CYANCOLOR "\033[1;36m"
#define ENDCOLOR "\033[0m"

class Date {
private:
    std::string data;
public:
    Date(void);
    ~Date(void);
public:
    static bool valid(std::string data);
    static bool checkDate(int year, int month, int day);
    static const char* DATEFORMAT;

};

class File {
public:
    typedef std::map<std::string, float> DBType;
private:
    DBType _db;
    std::string     _fileName;
	std::ifstream   _in;
	File(void);
public:
	File(char* name);
	int readDB(std::string sep);
	int readFile(std::string sep);
    DBType db(void) const;
    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trim(const std::string &s);
public:
    static const std::string WHITESPACE;
    static const std::string SEPARATOR_DATE;
    static const std::string SEPARATOR_PIPE;
    static const std::string SEPARATOR_COMMA;
    static const std::string DB_PATH;
};

#endif