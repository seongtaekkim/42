#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
    }
    File file;
    file.readFile(",");
    File::DBType _db = file.db();

    File file2(argv[1]);
    file2.readFile2("|", _db);
    File::DBType data = file2.db();

    // File::DBType::iterator dataIt = data.begin();
// 
    // for (File::DBType::iterator i = dataIt ; i != data.end() ; ++i) {
    //     // std::cout << i->first << std::endl;
    //     File::DBType::iterator fit = _db.find(i->first);
    //     if (fit != _db.end()) {
    //         std::list<float> l = fit->second;
    //         std::list<float>::iterator lit = l.begin();
    //         for (std::list<float>::iterator j = lit ; j != l.end() ; ++j) {
    //             //if ()
    //             //std::cout << one->first << " " << one->second << std::endl;

    //         }
    //     }
    // }

    return (0);
}