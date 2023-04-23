#include <vector>
using namespace std;
#include <iostream>

#include "stack.hpp"
#include <stack>
#include "vector.hpp"
#include <string>
#include <deque>
#include <map>
#include "map.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096


struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))
int main(int argc, char *argv[]){

	/*
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = v.begin();
	cout << *(it + 3) << endl;

	std::stack<int> st;
	st.push(1);

	ft::stack<int> s, s2;
	s.push(2);
	s2.push(2);
	s2.push(3);

	// std::cout << st.top() << std::endl;
	if (s != s2)
		std::cout << s.top() << std::endl;
	ft::stack<int> s3(s2);
	if (s2 == s3)
		std::cout << "s3 is same with s2" <<std::endl;
	s3.pop();
	std::cout << s3.size() <<std::endl;
	std::cout << s3.top() <<std::endl;
	std::cout << "empty ? : " << s3.empty() << std::endl;
	std::cout << s3.top() <<std::endl;
	std::cout<< s3.size() << std::endl;
	s3.pop();
	std::cout << "empty ? : " << s3.empty() << std::endl;

	*/

	// std::map<int, int> map_int;
	// map_int.insert(std::make_pair(1,1));
	// map_int.insert(std::make_pair(1,2));
	// map_int.insert(std::make_pair(2,22));
	
	// std::cout << map_int[1] <<std::endl;
	// std::cout << map_int[2] <<std::endl;

	ft::map<int, const char*> m;

	m.insert(ft::make_pair(0,"zero"));
	m.insert(ft::make_pair(1,"one"));
	m.insert(ft::make_pair(2,"two"));
	m.insert(ft::make_pair(3,"three"));
	m.insert(ft::make_pair(4,"four"));

	std::cout << m[0] << std::endl;
 
    {

		/*
			equal_range(key) 는 리턴 형태가 pair<iterator, iterator> 인데, 
			첫번째 iterator 는 lower_bound, 두번째 iterator 는 upper_bound 이다.
		*/
        ft::pair<ft::map<int, const char *>::iterator, ft::map<int, const char *>::iterator> p = m.equal_range(12);
		if (m.end() == p.first)
			std::cout << "equal range's lowerbound is not found" << std::endl;
		std::cout << (p.first)->first << "  " << p.second->first << std::endl;
        // for (auto& q = p.first; q != p.second; ++q) {
        //     std::cout << "m[" << q->first << "] = " << q->second << '\n';
        // }
		ft::map<int, const char*>::const_iterator it2 =  p.first;
		std::cout << it2->first << " " << it2->second << std::endl;
		
		ft::map<int, const char*>::const_iterator it3 =  p.second;
		std::cout << it3->first << " " << it3->second << std::endl;
		
		// lower_bound(key) 는 키 값 보다 크거나 같은 값을 갖는 최초의 원소 부분에 대한 iterator 를 찾아서 리턴한다.
		// upper_bound(key) 는 키 값 보다 큰 값이 최초로 나오는 지점에 대한 iterator 를 리턴한다
		// std::map<int, const char*>::const_iterator it =  (m.lower_bound(3));
		// std::cout << it->first << std::endl;

		ft::map<int, const char*>::const_iterator it4 =  m.find(6);
		if (m.end() == it4)
			std::cout << "not found " << std::endl;
		else
			std::cout << it4->first << " "  << it4->second << std::endl;
		ft::map<int, const char*>::key_compare k = m.key_comp();

		
		m.insert(ft::make_pair(7,"seven"));
	
		if (k(1,2))
			std::cout << "same " << std::endl;
		else
			std::cout << "end " << std::endl;

		//m.erase(2);

    }

}