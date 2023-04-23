#include <iostream>
#include <vector>

int main(void)
{


	/*
	Using vector.end() is a common and safe practice in C++, and it is not expected to cause a segmentation fault.
	However, it is important to note that dereferencing the end() iterator, such as by using *vector.end(), is undefined behavior and can potentially cause a segmentation fault or other unexpected behavior. (편집됨) 
	*/
	std::vector<std::string> v;
	v.push_back("aa");
	v.push_back("bb");
	v.push_back("bb");
	// std::vector<std::string>::iterator it = v.begin();
	std::vector<std::string>::iterator eit = v.end();
	// std::vector<std::string>::reverse_iterator rit = v.rbegin(); // end - 1
	// std::vector<std::string>::reverse_iterator reit = v.rend();
	// std::cout << *it <<std::endl;
	// std::cout << *eit <<std::endl;
	// std::cout << *rit <<std::endl;
	// std::cout << v.capacity() << std::endl;
		std::cout << "||"  << *(eit) << "|| "<<std::endl;
	return(0);
}