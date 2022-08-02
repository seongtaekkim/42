#include <iostream>
#include <string>

using namespace std;

/*
 * template를 이용해서 generic programming을 할 수 있다.ㅇ
 * 함수템플릿(function template)
 * - 각각의 자료형에 대해 처음호출될 때 c++컴파일러는 해당 타입의 인스턴스를 생성하게 된다.
 *   이후 생성된 ㅅ하나의 인스턴스는 해당 자료형에 대해 특수화가 이루어진다.
 * 명시적특수화
 * - 특정타입에 대하여 명시적특수화 기능을 제공한다. (특정 타입에대해 특수기능을 정의)
 * 클래스템플릿
 * - 자료형에 따라 다르게 동작하는 클래스 집합을 만들 수 있다.
 */
template <typename T>
void change(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// 명시적 특수화
template <>
void change<int>(int& a, int& b)
{
	cout << "정수형 데이터를 교체합니다.\n";
	int temp;
	temp = a;
	a = b;
	b= temp;
}

// 클래스 템플
template <typename T>
class Data
{
	private:
		T data;
	public:
		Data(T data) : data(data) { }
		void setData(T data) { this->data = data; }
		T getData() { return data; }
};

int	main(void)
{
	string a = "seongtki";
	string b = "kim";
	change(a, b);
	cout << a << ":" << b << endl;

	Data<int> data1(1);
	Data<string> data2("segontki");
	cout << data1.getData() << ":" << data2.getData() << "\n";
}
