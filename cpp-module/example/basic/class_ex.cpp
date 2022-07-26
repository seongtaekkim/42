#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		string	name;
		int		englishScore;
		int		mathScore;
		int		getSum() { return englishScore + mathScore; }
	public:
		Student(string name, int englishScore, int mathScore)
		{
			this->name = name;
			this->englishScore = englishScore;
			this->mathScore = mathScore;
		}
		void show() { cout << name << " : [합계 " << getSum() << "점]\n"; }
};

class Character
{
	private:
		string 	name;
		int		rangePoint;
		int		hp;
		int		damage;
	public:
		Character(string name, int hp, int damage) : name(name), rangePoint(0), hp(hp), damage(damage) { };
		~Character()
		{
			cout << rangePoint << "[객체가 소멸됩니다.]\n";
		}
		Character(const Character& other)
		{
			name = other.name;
			rangePoint = other.rangePoint;
			hp = other.hp;
			damage = other.damage;
		}
		void pointUp() { rangePoint++; }
		void show()
		{
			cout << name << "[" << rangePoint << "]" << hp << " " << damage << '\n';
		}
};

int	main(void)
{
	/* ex1 */
	Student student = Student("seongtki", 100, 100);
	student.show();
	/* ex2 - 복사생성자 */
	/*
	Character character1("kimm", 10, 20);
	character1.pointUp();
	Character character2(character1);
	character2.pointUp();
	character1.show();
	character2.show();
	*/
	/* ex3 - 소멸자*/
	/* 객체의 수명이 끝났을 때 객체를 제거하기 위한 목적으로 사용.
	 * ㅇ객체의 수명이 끝났을 때 자동으로 컴파일러가 소멸자 함수를 호출함.
	 * ~클래스명 으로 정의함.
	 */
	Character* c1 = new Character("kim2", 10, 20); // 동적할당하여 생성한 객체는 명시적으로 해제해야 함.
	c1->pointUp();
	Character c2(*c1); // 복사생성된 인스턴스는 프로그램 종료되면서 해제됨.
	c2.pointUp();
	c2.pointUp();
	c1->show();
	c2.show();
	
	delete c1;  // 동적할당 된 인스턴스 해제
	//delete &c2; // 이미 해제 되어 있음
}
