
#include <iostream>
#include <vector>

template <class T>
void print_vector(std::vector<T>& vec) {
  typename std::vector<T>::iterator itr;
  for ( itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << std::endl;
  }
}
int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  std::cout << "벡터 상태" << std::endl;
  print_vector(vec);
  std::cout << "----------------------------" << std::endl;

	return 0;
}