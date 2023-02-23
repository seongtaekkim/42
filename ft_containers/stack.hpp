#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{

template <typename _Tp, typename _Container= ft::vector<_Tp> >
class stack
{
public:
	typedef typename _Container::value_type      value_type;
	typedef typename _Container::size_type       size_type;
	typedef typename _Container::reference       reference;
	typedef typename _Container::const_reference const_reference;
	typedef          _Container                  container_type;
protected:
	_Container c;
public:
	stack() : c() {}
	explicit stack(const _Container& __s) : c(__s) {}
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	reference top() { return c.back(); }
	const_reference top() const { return c.back(); }
	void push(const value_type& __x) { c.push_back(__x); }
	void pop() { c.pop_back(); }
private:
	template <typename _Tp1, typename _Seq1>
	friend bool operator== (const stack<_Tp1, _Seq1>&, const stack<_Tp1, _Seq1>&);
	template <typename _Tp1, typename _Seq1>
	friend bool operator< (const stack<_Tp1, _Seq1>&, const stack<_Tp1, _Seq1>&);
};

template <typename _Tp, typename _Seq>
bool operator==(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return __x.c == __y.c;
}

template <typename _Tp, typename _Seq>
bool operator<(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return __x.c < __y.c;
}

template <typename _Tp, typename _Seq>
bool operator!=(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return !(__x == __y);
}

template <typename _Tp, typename _Seq>
bool operator>(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return __y < __x;
}

template <typename _Tp, typename _Seq>
bool operator<=(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return !(__y < __x);
}

template <typename _Tp, typename _Seq>
bool operator>=(const stack<_Tp,_Seq>& __x, const stack<_Tp,_Seq>& __y)
{
  return !(__x < __y);
}

}

#endif
