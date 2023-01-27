#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> 
#include <set>

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
 
int main()
{
    // std::vector<int> v(3, 1, -14, 1, 5, 9); 
    std::vector<int>::iterator result;

		std::vector<int> v;
	srand(time(NULL));
	for (int i = 0 ; i < 10000 ; i++)
		v.push_back(rand());
 
    result = std::max_element(v.begin(), v.end());
    std::cout << "max element found at index "
              << std::distance(v.begin(), result)
              << " has value " << *result << '\n';
 
    // result = std::max_element(v.begin(), v.end(), [](int a, int b) {
    //     return std::abs(a) < std::abs(b);
    // });
    // std::cout << "absolute max element found at index "
    //           << std::distance(v.begin(), result)
    //           << " has value " << *result << '\n';
}

// int main(void)
// {
// 	std::vector<int> a;
// 	std::multiset<int> b;
// 	a.begin();
// 	/// sort -> adjacent_difference -> min_element 

// 	return (0);
// }