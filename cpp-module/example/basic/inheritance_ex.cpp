#include <iostream>
#include <string>

using namespace std;

class Person
{
	private:
		string name;
	public:
		Person(string name) : name(name) { }
		string getName()
		{
			return name;
		}
		void showName()
		{
			cout << "이름: " << getName() << '\n';
		}
};

class Temp
{
	public:
		void showTemp()
		{
			cout << "임시 부모클래스 temp\n";
		}
};

/*
 * 1. 상속
 *  - 부모의 속성을 그대로 가져옴
 * 2. 오버라이딩
 *  - 부모의 함수를 재정의 하는것
 * 3. 다중상속
 *  - 상속 변수,함수 등 중복이슈로 잘 사용하지 않음.
 *  - temp class는 왜 public 해야 상속받을 수 있는거지?
 * 
 */
class Student : Person, public Temp
{
	private:
		int studentId;
	public:
		Student(int studentId, string name) : Person(name)
		{
			this->studentId = studentId;
		}
		void show()
		{
			cout << "학생번호: " << studentId << '\n';
			cout << "학생이름: " << getName() << '\n';
		}
		void showName()
		{
			cout << "학생이름: " << getName() << '\n';
		}
};

int	main(void)
{
	Student student(1, "seongtki");
	student.show();
	student.showName();
	student.showTemp();
}
