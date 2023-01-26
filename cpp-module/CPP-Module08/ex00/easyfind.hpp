#include <iostream>
#include <algorithm>

class FindException {
public:
    void report() const {
      std::cerr << "not found data" << std::endl;  
    }
};

template<typename T>
typename T::iterator easyfind(T &container,  int n) {
    typename T::iterator iterator;
    
    iterator = std::find(container.begin(), container.end(), n);
    if (iterator == container.end())
        throw FindException();
    return (iterator);
}