#include <iostream>
#include <fstream>


class Replace
{
private:
    std::string fileName;
public:


};

/*
1. 파일명, s1 s2 문자열 프로그램 인자
2. 파일에서 s1문자열을 s2 문자열로 대체하는 replace 생성
s1이 존재할 때까지 읽는걸ㄹ ㅗ
3. 예외처리.
4. 테스트파일
*/
int main(int argc, char *argv[])
{
    std::ofstream of;
    std::string str;

    if (argc != 4)
        return (0);
    
  std::ifstream in("out.txt");
  char buf[100];

  if (!in.is_open()) {
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    return 0;
  }

  while (in) {
    in.getline(buf, 100);
    std::cout << buf << std::endl;
  }

  in.close();
of.open("out2.txt");
of.close();
    return (0);
}