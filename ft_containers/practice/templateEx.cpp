
#include <iostream>
#include <vector>


/*
SFINAE, enable_if 설명
- 좀 부실함
https://modoocode.com/255

SFINAE, enable_if 설명
https://koreanfoodie.me/958
*/

/*
컴파일러가 오버로딩 후보들을 살펴볼 때 첫 번째 버전은 타입 변환이 필요하지만 (unsigned 를 붙여야 되죠), 
두 번째 버전은 타입 변환 없이 그냥 T 를 int 로 끼워넣으면 되기 때문에 결국 두 번째 후보가 채택됩니다.
*/
template <typename T>
void foo(const T& t) {
  std::cout << "template " << t << "\n";
}

void foo(unsigned int i) { std::cout << "unsigned " << i << "\n"; }

int negate(int i) { return -i; }

// SFINAE
// 치환 실패는 오류가 아니다 - Substitution Failure Is Not An Error
// 스피내
template <typename T>
typename T::value_type negate(const T& t) {
  return -T(t);
}

// immediate context 에서 벗어남
template <typename T>
void negate(const T& t) {
  typename T::value_type n = -t();
}


// 함수 템플릿 기본형
template <bool, typename T = void>
struct enable_if {};


// 함수템플릿 특수화
// 첫번 째 템플릿  인자가 true 일 경우에만 type을 정의한다.
// 그렇지 못하면 (false) 컴파일 에러.
template <typename T>
struct enable_if<true, T> {
  typedef T type;
};

template <typename T, typename = typename enable_if<std::is_integral<T>::value>::type>
void test(const T& t) {
	std::cout << "t : " << t << std::endl;
}

int main(void) {

	// SFINAE test
	foo(42);
	std::cout << negate(42) << std::endl;
	std::vector<int> v1(4, 8);
	
	// enable_if && is_integral test
	test(1);	// int
	test(false);	// bool
	test('c');	// char
	return (0);
}