#include <vector>
#include <iostream>
#include "../vector.hpp"
template <typename T>
void print_container(const T& c)
{
    // for (iterator iter = c.begin(); iter != c.end(); iter++)
    for (size_t idx = 0; idx < c.size(); idx++)
        std::cout << c[idx] << " ";
    std::cout << '\n';
}
/*
    - empty
    - end()
    별도의 예외처리는 없는 듯 하다.
*/
int main( )
{
    ft::vector<int> c;
    for (int i=0; i<10; i++)
        c.push_back(i);
    // std::vector<int> c(5, 1152);
    print_container(c);
    // c.erase(c.begin());
    // print_container(c);
    c.erase(c.end(), c.begin());
    return (0);
}