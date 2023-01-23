#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    v.push_back(4);
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    std::vector<int>::iterator it  = std::find(v.begin(), v.end(), 4);
    std::cout << *it << std::endl;

    try
    {
        std::cout << *easyfind(v, 10) << std::endl;;
        std::cout << *easyfind(v, 103) << std::endl;;
    }
    catch(FindException &e)
    {
        e.report();
    }
    return (0);
}
