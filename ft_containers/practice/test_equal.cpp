#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string_view>
 
 #include "../alghrithm.hpp"

 /*
 https://woo-dev.tistory.com/20
 https://en.cppreference.com/w/cpp/algorithm/equal
 */

const bool is_palindrome(const std::string_view& s)
{
    return ft::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}
 
void test(const std::string_view& s)
{
    std::cout << (is_palindrome(s) ? " is" : " is not") << " a palindrome\n";
}
 
int main()
{
    test("radar");
    test("hello");
}