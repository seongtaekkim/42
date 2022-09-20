#include "easyfind.hpp"
#include <iostream>
#include <vector>
    using namespace std;

template<typename T>
typename std::vector<T>::iterator easyfind(std::vector<T> v, int n)
{
    try
    {
        typename std::vector<T>::iterator it  = std::find(v.begin(), v.end(), 4);
        return (it);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw;
    }
}


int main(void)
{
    std::vector<int> v;
    v.push_back(4);
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    //easyfind(v, 3);
    std::vector<int>::iterator it  = std::find(v.begin(), v.end(), 4);
    cout << *it << endl;

    cout << *easyfind(v, 4) << endl;;
    return (0);
}