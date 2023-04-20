#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>


class Date {
private:
    std::string data;
public:
    // Date(std::string data);
    Date(void);
    ~Date(void);
    static bool valid(std::string data);
};

class BitcoinExchange {
public:
    typedef std::map<Date, float> DBType;
private:
    DBType _dbMap;
public:

};

// #include <set>
#include <list>
class File {
public:
    typedef std::map<std::string, float> DBType;
private:
    DBType _db;
private:
    std::string fileName;
	std::ifstream in;
public:
	File(void);
	File(char* name);
	// int readFile(char* dest);
	int readFile(std::string sep);
	int readFile2(std::string sep, DBType db);
	// int replace();
	// int saveFile(); 
    DBType db(void) const;
};

#endif