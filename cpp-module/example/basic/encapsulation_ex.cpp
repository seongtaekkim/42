#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
 * friend
 * c++에서는 맴버변수에 접근하기하려면 pulic이어야 한다. 예외사항은, friend를 이용했을 경우다.
 * 아래는 operator overoading에 다른객체를 인자로 사용 할 때의 friend 사용 예시이다.
 */
class Student
{
	private:
		int	studentId;
		string	name;
	public:
		Student(int studentId, string name) : studentId(studentId), name(name) { }
		friend Student operator +(const Student &student, const Student &other)
		{
			return Student(student.studentId, student.name + " & " + other.name);
		}
		void showName() { cout << "이름 : " << name << '\n'; }
};

/*
 * friend class
 * 두 클래스가 밀접해서, private 맴버변수에 접근해야 할 때 friend class를 사용한다.
 */
class Time
{
	friend class Date;
	private:
		int	hour, min, sec;
	public:
		void setCurrentTime()
		{
			time_t currentTime = time(NULL);
			struct tm *p = localtime(&currentTime);
			hour = p->tm_hour;
			min = p->tm_min;
			sec = p->tm_sec;
		}
};

class Date
{
	private:
		int	year, month, day;
	public:
		Date(int year, int month, int day) : year(year), month(month), day(day) { }
		void show(const Time &t)
		{
			cout << "지정된 날짜 : " << year << "년 " << month << "월 " << day << "일" << '\n';
			cout << "현재시간: " << t.hour << ":" << t.min << ":" << t.sec << '\n';
		}
};

/*
 * 정적맴버 (static member)
 * - 클래스에 포함되어있는 맴버이지만, 모든 객체가 공유하는 맴버이다. 
 * - 메모리상에 오직 하나만 할당되어 관리된다.
 * 상수멤버 (constant member)
 * - 호출된 객체의 데이터를 변경할 수 없는 멤버를 의미한다.
 * - 초기화 후 변경이 불가하다.
 */
class Person
{
	private:
		const int id;
		string name;
	public:
		static int count;
		Person(int id, string name) : id(id), name(name)
		{
			count++;
		}
		/*
		void setid(int id)
		{
			this->id = id;
		}
		*/
};

int Person::count = 0;

int	main(void)
{
	Student student(1, "seongtki");
	Student result = student + student;
	result.showName();
	
	Time time;
	time.setCurrentTime();
	Date date = Date(2019, 12, 22);
	date.show(time);
	
	Person p1(1, "이름1");
	Person p2(2, "이름2");
	Person p3(3, "이름3");
	cout << "사람 수: " << Person::count << '\n';
}
