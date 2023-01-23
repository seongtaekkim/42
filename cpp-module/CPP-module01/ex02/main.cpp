#include <iostream>
#include <string>

int main(void)
{
    const std::string str = "HI THIS IS BREAN";
    const std::string *stringPTR = &str;
    const std::string &stringREF = str;

    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return (0);
}
