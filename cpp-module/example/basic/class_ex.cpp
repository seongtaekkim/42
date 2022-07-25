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

int	main(void)
{
	Student student = Student("seongtki", 100, 100);
	student.show();
}
