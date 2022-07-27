#include <iostream>
#include <string>

using namespace std;

/*
 * [overloading]
 * - 생성자, 함수의 이름은 같고 인자가 다른 함수
 * [operator overloading]
 * - 기존에 존재하는 연산자만 정의할 수 있다.
 * - 멤버연산자(.), 범위지정연산자(::) 등의 몇몇 연산자는 오버로딩할 수 없다.
 * - 피연산자 개수규칙 등 기본적인 연산자 규칙을 따라야 한다. 
 * - 오버로딩된 연산자의 피연산자중 하나는 사용자정의 자료형이어야 한다/
 */
class Person
{
	private:
		string name;
	public:
		Person() { name = "seongtki"; }
		Person(string name) : name(name) { }
		Person operator +( Person& other) { return Person( name + " & " + other.name); }
		void showName() { cout << "name is " << name << '\n'; }		
};

int	main(void)
{
	Person p1;
	p1.showName();
	Person p2("kim");
	p2.showName();

	Person p3 = p1 + p2;
	p3.showName();
	return (0);
}
