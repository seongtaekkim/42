#include "Array.hpp"

template <typename T>
void typeTest(unsigned int size)
{
	Array<T> a(size);

	std::cout << "Value Test" << std::endl;
	for (unsigned int i = 0 ; i < size ; ++i)
	{
		a[i] = static_cast<T>(i + '0');
		std::cout << a[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Exception Test" << std::endl;
	try
	{
		std::cout << a[size] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "========== Int Test ==========" << std::endl;
	typeTest<int>(10);
	std::cout << std::endl;

	std::cout << "========== Double Test ==========" << std::endl;
	typeTest<double>(10);
	std::cout << std::endl;

	std::cout << "========== Char Test ==========" << std::endl;
	typeTest<char>(10);
	std::cout << std::endl;

	std::cout << "========== Const Test ==========" << std::endl;
	const Array<char> c(10);
	for (unsigned int i = 0 ; i < 10; ++i)
	{
		try {
		*(const_cast<char*>(&c[i])) = static_cast<char>(i + '0');
		std::cout << c[i] << " ";
		} catch (std::exception& e) {std::cerr << e.what() << std::endl;}
	}
	std::cout << std::endl << std::endl;
	std::cout << "========== Copy Test ==========" << std::endl;
	Array<std::string> arr1(3);
	arr1[0] = "Hi";
	arr1[1] = "42";
	arr1[2] = "Seoul";
	Array<std::string> arr2(arr1);
	for (unsigned int i = 0 ; i < arr1.size() ; ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0 ; i < arr1.size() ; ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	return (0);
}
