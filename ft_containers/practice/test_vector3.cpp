#include <iostream>
#include <vector>
#include "../vector.hpp"
#include <sys/time.h>
int _ratio = 10000;
volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}


class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};


template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    return v;
}

template <typename T>
std::vector<int> resize_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);;
    return v;
}



template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

template <typename T>
std::vector<int> insert_test_3(ft::vector<T> vector) {
    std::vector<int> v;
    ft::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;
	std::cout << &(*k2) << std::endl;
    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}


template <typename T>
std::vector<int> swap_test(ft::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1100 * 10000, 11);
    ft::vector<int> tmp(500 * 10000, 5), tmp2(1000 * 10000, 10), tmp3(1500 * 10000, 15), tmp4(3000 * 10000, 30);
    g_start2 = timer();
	std::cout << g_start2 << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
	std::cout << "step1" << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	std::cout << "step1" << std::endl;
    ft::swap(vector, tmp2);
	std::cout << "step1" << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    ft::swap(vector, tmp4);
    g_end2 = timer();
	std::cout << g_end2 << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}


template <typename T>
std::vector<int> swap_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(1100 * 10000, 11);
    std::vector<int> tmp(500 * 10000, 5), tmp2(1000 * 10000, 10), tmp3(1500 * 10000, 15), tmp4(3000 * 10000, 30);
    g_start1 = timer();
	std::cout << g_start1 << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
		std::cout << "step1" << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp2);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp4);
    g_end1 = timer();
	std::cout << g_end1 << std::endl;
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main(void)
{
	ft::vector<int> v;
	//  std::vector<int> v;

	/*
		std::swap 에서 중간에 캐패시터가 늘어나는 이유
		swap하면 중간에 copy assignment를 타는데,
		해당 함수에
		이미 늘어난 캐패시터를 줄이는 기능이 없다.

		std::swap에서 속도저하는 다시 체크해야 한다.
	*/
	std::vector<int> ret = swap_test(v);
	std::cout << g_end1 - g_start1 << std::endl;
	std::cout << g_end2 - g_start2 << std::endl;

	/*
		캐패시터 다름
	*/
	// std::vector<int> ret = resize_test(v);

	/*
		range inssert
		입력안되는 값이 들어왔을 때, 예외처리 부분이 없다.
	*/
	// std::vector<int> ret = insert_test_3(v);

	std::vector<int>::iterator sit = ret.begin();
	std::vector<int>::iterator eit = ret.end();
	for (; sit != eit ; sit++)
		std::cout << *sit << std::endl;
	// std::cout << ret[0] << std::endl;
	// std::cout << ret[1] << std::endl;
	// std::cout << ret[2] << std::endl;
	// std::cout << ret[3] << std::endl;
	// std::cout << ret[4] << std::endl;
	// std::cout << ret[5] << std::endl;
	// std::cout << ret[6] << std::endl;

	ft::vector<int> v10;
	v10.assign(100,42);

	ft::vector<int> v11;
	
	ft::vector<int>::iterator sit2 = v10.begin();
	ft::vector<int>::iterator eit2 = v10.end();
	v11.insert(v11.begin(), sit2, eit2);
	
	return (0);
}