#include <cassert>
#include <iostream>
#include <map>
#include "../map.hpp"
 
// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};
 
int main()
{
	// compare 의 default 는  std::less<key> 이다.
	// ModCmp 으로 compare 로직을 정할 수 있다.
    ft::map<int, char, ModCmp> cont;
    // cont = { { 1, 'a' }, { 2, 'b' }, { 3, 'c' }, { 4, 'd' }, { 5, 'e' } };
	cont.insert(ft::make_pair(1,'a'));
	cont.insert(ft::make_pair(2,'b'));
	cont.insert(ft::make_pair(3,'c'));
	cont.insert(ft::make_pair(4,'d'));
	cont.insert(ft::make_pair(5,'e'));
	
    auto comp_func = cont.key_comp();
 
    for (auto it : cont) {
		std::cout << it.first << "  ";
        bool before = comp_func(it.first, 100);
        bool after = comp_func(100, it.first);
 
        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key 100\n";
        else if (before)
            std::cout << ") goes before key 100\n";
        else if (after)
            std::cout << ") goes after key 100\n";
        else
            assert(0); // Cannot happen
    }
}