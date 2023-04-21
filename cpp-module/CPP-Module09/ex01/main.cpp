#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: please input one parameter" << std::endl;
        return (1);
    }

    std::vector<int> vec;
    char* stop;
    int result;
    std::string str = argv[1];
    std::size_t before = 0;
    std::size_t after = 0;

    while (true) {

        after = str.find_first_not_of(" ", before);
        if (after == std::string::npos) break ;
        before = str.find(" ", after);
        if (before == std::string::npos) {
            if (after == str.size() - 1) {
                before = str.size();
            }
        }
        std::string ret = str.substr(after, before - after);
        stop = NULL;
        result = 0;

        int data = ::strtol(ret.c_str(), &stop, 10);
        if (*stop == 0) {
            vec.push_back(data);
        } else {
            if (std::string(stop).size() > 1) {
                std::cerr << "Error" << std::endl;
                return (1);      
            }
            if (*stop == '*' || *stop == '-' || *stop == '+' || *stop == '/') {
                if (vec.size() < 2) {
                    std::cerr << "Error: size unbound" << std::endl;
                    return (1);
                }
                int second = vec.back();
                vec.pop_back();
                int first = vec.back();
                vec.pop_back();
                if (*stop == '+')
                    result = first + second;
                else if (*stop == '-')
                    result = first - second;
                else if (*stop == '*')
                    result = first * second;
                else if (*stop == '/') {
                    if (second == 0) {
                        std::cerr << "Error: divide error" << std::endl;
                        return (1);
                    }
                    result = first / second;
                }
                vec.push_back(result);
            } else {
                std::cerr << "Error" << std::endl;
                return (1);
            }
        }
    }
    if (vec.size() != 1)
        std::cerr << "Error: not enough operator" << std::endl;
    else if (vec.size() == 0)
        std::cerr << "Error: not enough number" << std::endl;
    else
        std::cout << vec.front() << std::endl;
}