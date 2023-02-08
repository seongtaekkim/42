
#include <iostream>


/*
컴파일러가 오버로딩 후보들을 살펴볼 때 첫 번째 버전은 타입 변환이 필요하지만 (unsigned 를 붙여야 되죠), 
두 번째 버전은 타입 변환 없이 그냥 T 를 int 로 끼워넣으면 되기 때문에 결국 두 번째 후보가 채택됩니다.
*/
template <typename T>
void foo(const T& t) {
  std::cout << "template " << t << "\n";
}

void foo(unsigned int i) { std::cout << "unsigned " << i << "\n"; }

int main(void) {
	foo(42);
	return (0);
}