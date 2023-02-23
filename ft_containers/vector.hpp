
#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "algorithm.hpp"
#include "utility.hpp"

namespace ft
{

template <typename _T, typename _Allocator = std::allocator<_T>()>
struct __vector_base {

 public:
  typedef _Allocator								allocator_type;

 protected:
  typedef _T										value_type;
  typedef size_t									size_type;
  typedef ptrdiff_t   								difference_type;
  typedef typename allocator_type::reference 		reference;
  typedef typename allocator_type::const_reference 	const_reference;
  typedef typename allocator_type::pointer 			pointer;
  typedef typename allocator_type::const_pointer 	const_pointer;

  pointer			__begin_;
  pointer			__end_;
  pointer			__end_cap_;
  allocator_type	__a_;

  __vector_base() throw();
  __vector_base(const allocator_type& a) throw();
  __vector_base(size_type n);
  __vector_base(size_type n, const allocator_type& alloc);
  ~__vector_base() throw() {
    if (__begin_) __a_.deallocate(__begin_, __end_cap_ - __begin_);
  }

  size_type __capacity() const throw() {
    return static_cast<size_type>(__end_cap_ - __begin_);
  }

  size_type __check_length(size_type __n) {
    if (__n >= __a_.max_size())
		__throw_length_error("vector: size is too big");
    return __n;
  }

  void __destruct_storage() throw();
  pointer __construct_storage(size_type __n) {
    return __n == 0 ? pointer() : __a_.allocate(__n);
  };

  void __copy_data(__vector_base const& _other) throw();
  void __copy_data(pointer const& __new_begin_, pointer const& __new_end, pointer const& __new_end_cap_) throw();
  void __swap_data(__vector_base& _other) throw();

  void __throw_length_error(const char* msg) const {
    throw std::length_error(msg);
  }
  void __throw_out_of_range(const char* msg) const {
    throw std::out_of_range(msg);
  }

  

 private:
  __vector_base(const __vector_base& other) { (void)other; }
  __vector_base& operator=(const __vector_base& other) { (void)other; }
}; 







template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base() throw()
    : __begin_(NULL),
      __end_(NULL),
      __end_cap_(NULL),
      __a_(std::allocator<_T>()) {}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(const allocator_type& a)
    throw() : __begin_(NULL),
                  __end_(NULL),
                  __end_cap_(NULL),
                  __a_(a) {}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(size_type __n)
    : __a_(std::allocator<_T>()) {
  __begin_ = __construct_storage(__n);
  __end_ = __begin_;
  __end_cap_ = __begin_ + __n;
}

template <typename _T, typename _Allocator>
__vector_base<_T, _Allocator>::__vector_base(size_type __n,
                                             const allocator_type& a)
    : __a_(a) {
  __begin_ = __construct_storage(__n);
  __end_ = __begin_;
  __end_cap_ = __begin_ + __n;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__copy_data(__vector_base const& _other)
    throw() {
  __begin_ = _other.__begin_;
  __end_ = _other.__end_;
  __end_cap_ = _other.__end_cap_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__copy_data(
    pointer const& __new_begin_, pointer const& __new_end,
    pointer const& __new_end_cap_) throw() {
  __begin_ = __new_begin_;
  __end_ = __new_end;
  __end_cap_ = __new_end_cap_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__swap_data(__vector_base& _other)
    throw() {
  pointer __tmp_begin_(__begin_);
  pointer __tmp_end_(__end_);
  pointer __tmp_end_cap_(__end_cap_);
  allocator_type __tmp_a_(__a_);
  this->__copy_data(_other);
  this->__a_ = _other.__a_;
  _other.__copy_data(__tmp_begin_, __tmp_end_, __tmp_end_cap_);
  _other.__a_ = __tmp_a_;
}

template <typename _T, typename _Allocator>
void __vector_base<_T, _Allocator>::__destruct_storage() throw() {
  __a_.deallocate(__begin_, __capacity());
  __end_ = __begin_ = __end_cap_ = NULL;
}



template <typename _Iter>
class __vector_iterator {
 public:
  typedef _Iter iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category
      iterator_category;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type
      difference_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;

 private:
  iterator_type __it;

 public:
  __vector_iterator() throw() {}
  template <typename _U>
  __vector_iterator(
      const __vector_iterator<_U>& __u,
      typename enable_if<__is_random_access_iterator<_U>::value>::type* =
          0)  // can copy when the category is random_access
      throw() : __it(__u.base()) {}

  __vector_iterator(iterator_type __x) throw() : __it(__x) {}

  const iterator_type& base() const { return __it; }

  // operator
  reference operator*() const throw() { return *__it; }
  pointer operator->() const throw() { return __it; }
  __vector_iterator& operator++() throw() {
    ++__it;
    return *this;
  }
  __vector_iterator operator++(int) throw() {
    __vector_iterator __tmp(*this);
    ++(*this);
    return __tmp;
  }
  __vector_iterator& operator--() throw() {
    --__it;
    return *this;
  }
  __vector_iterator operator--(int) throw() {
    __vector_iterator __tmp(*this);
    --(*this);
    return __tmp;
  }
  __vector_iterator& operator+=(difference_type __n) {
    __it += __n;
    return *this;
  }
  __vector_iterator operator+(difference_type __n) const {
    __vector_iterator __w(*this);
    __w += __n;
    return __w;
  }
  __vector_iterator& operator-=(difference_type __n) {
    __it -= __n;
    return *this;
  }
  __vector_iterator operator-(difference_type __n) const {
    __vector_iterator __w(*this);
    __w -= __n;
    return __w;
  }
  reference operator[](difference_type __n) { return __it[__n]; }
};

template <typename _Iter1, typename _Iter2>
bool operator==(const __vector_iterator<_Iter1>& __lhs,
                const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() == __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator!=(const __vector_iterator<_Iter1>& __lhs,
                const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() != __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator<(const __vector_iterator<_Iter1>& __lhs,
               const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() < __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator>(const __vector_iterator<_Iter1>& __lhs,
               const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() > __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator>=(const __vector_iterator<_Iter1>& __lhs,
                const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() >= __rhs.base();
}

template <typename _Iter1, typename _Iter2>
bool operator<=(const __vector_iterator<_Iter1>& __lhs,
                const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() <= __rhs.base();
}

template <typename _Iter1, typename _Iter2>
typename __vector_iterator<_Iter1>::difference_type operator-(
    const __vector_iterator<_Iter1>& __lhs,
    const __vector_iterator<_Iter2>& __rhs) {
  return __lhs.base() - __rhs.base();
}

template <typename _Iter>
__vector_iterator<_Iter> operator+(
    typename __vector_iterator<_Iter>::difference_type __n,
    const __vector_iterator<_Iter>& __it) {
  return __vector_iterator<_Iter>(__it.base() + __n);
}










template <class _Tp, class _Alloc = std::allocator<_Tp> >
class vector : protected __vector_base<_Tp, _Alloc>
{
private:
  typedef __vector_base<_Tp, _Alloc> 					_Base;
  typedef vector<_Tp, _Alloc> 							vector_type;
public:
  typedef _Tp 											value_type;
  typedef value_type* 									pointer;
  typedef const value_type* 							const_pointer;
  typedef __vector_iterator<pointer> 		iterator;
  typedef __vector_iterator<const_pointer>	const_iterator;
  typedef value_type& 									reference;
  typedef const value_type& 							const_reference;
  typedef size_t 										size_type;
  typedef ptrdiff_t 									difference_type;

  typedef reverse_iterator<const_iterator>				const_reverse_iterator;
  typedef reverse_iterator<iterator>					reverse_iterator;

  typedef typename _Base::allocator_type				allocator_type;
  allocator_type get_allocator() const { return this->__a_;}

protected:
  void _M_insert_aux(iterator __position, const _Tp& __x);
  void _M_insert_aux(iterator __position);

  void __throw_length_error(const char* msg) const {
    throw std::length_error(msg);
  }
  void __throw_out_of_range(const char* msg) const {
    throw std::out_of_range(msg);
  }

public:
  
  iterator begin() { return iterator (this->__begin_); }
  const_iterator begin() const { return const_iterator (this->__begin_); }
  iterator end() { return iterator (this->__end_); }
  const_iterator end() const { return const_iterator (this->__end_); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
  size_type size() const { return size_type(end() - begin()); }
  size_type max_size() const { return size_type(-1) / sizeof(_Tp); }
  size_type capacity() const { return size_type(const_iterator(this->__end_cap_) - begin()); }

  bool empty() const { return begin() == end(); }

  reference operator[](size_type __n) { return *(begin() + __n); }
  const_reference operator[](size_type __n) const { return *(begin() + __n); }

  reference at(size_type __n) {
	if (__n >= this->size())
		this->__throw_out_of_range("vector: out of range");
	return (*this)[__n];
  }

  const_reference at(size_type __n) const {
	if (__n >= this->size())
		this->__throw_out_of_range("vector: out of range");
	return (*this)[__n];
  }

  /*
	===========================================
	constructor
	===========================================
  */
  explicit vector(const allocator_type& __a = allocator_type()) : _Base(__a) {}

  vector(size_type __n, const _Tp& __value, const allocator_type& __a = allocator_type()) : _Base(__n, __a) { 
	this->__end_ = std::uninitialized_fill_n(this->__begin_, __n, __value);
  }

  explicit vector(size_type __n) : _Base(__n, allocator_type()) {
  	this->__end_ = std::uninitialized_fill_n(this->__begin_, __n, _Tp());
  }

// 지우셈
  vector(const vector<_Tp, _Alloc>& __x)
    : _Base(__x.size(), __x.get_allocator())
    { this->__end_ = std::uninitialized_copy(__x.begin(), __x.end(), this->__begin_); }

  // Check whether it's an integral type.  If so, it's not an iterator.
  template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type())
	: _Base(__a)
	{
      typedef typename is_integral<_InputIterator>::type _Integral;
      _M_initialize_aux(__first, __last, _Integral());
    }

  template <class _Integer>
    void _M_initialize_aux(_Integer __n, _Integer __value, true_type)
	{
      this->__begin_ = this->__a_.allocate(__n);
      this->__end_cap_ = this->__begin_ + __n;
      this->__end_ = std::uninitialized_fill_n(this->__begin_, __n, __value);
    }

  template<class _InputIterator>
    void
	_M_initialize_aux(_InputIterator __first, _InputIterator __last, false_type)
	{
	  typedef typename iterator_traits<_InputIterator>::iterator_category _IterCategory;
	  _M_range_initialize(__first, __last, _IterCategory());
	}

  ~vector() {
	_Destroy(this->__begin_, this->__end_);
  }


  template <class _Tp2>
  void _Destroy(_Tp2 *_pointer){
	_pointer->~_Tp2();
  }

  void _Destroy(iterator _first, iterator _last) {
	iterator it = _first;
	for (; it!=_last; ++it){
		this->__a_.destroy(&(*it));
	}
  }






  vector<_Tp, _Alloc>& operator=(const vector<_Tp, _Alloc>& __x);

  void reserve(size_type __n) {
    if (capacity() < __n) {
      const size_type __old_size = size();
      pointer __tmp = _M_allocate_and_copy(__n, this->__begin_, this->__end_);
      _Destroy(this->__begin_, this->__end_);
      this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
      this->__begin_ = __tmp;
      this->__end_ = __tmp + __old_size;
      this->__end_cap_ = this->__begin_ + __n;
    }
  }


	void assign(size_type __n, const _Tp& __val) {
		_M_fill_assign(__n, __val);
	}
	
	void _M_fill_assign(size_type __n, const _Tp& __val);

	template<class _InputIterator>
    void
    assign(_InputIterator __first, _InputIterator __last) {
      typedef typename is_integral<_InputIterator>::type _Integral;
      _M_assign_dispatch(__first, __last, _Integral());
    }

  	template<class _Integer>
    void
    _M_assign_dispatch(_Integer __n, _Integer __val, true_type) {
		_M_fill_assign((size_type) __n, (_Tp) __val);
	}

	template<class _InputIter>
    void
    _M_assign_dispatch(_InputIter __first, _InputIter __last, false_type) {
    	typedef typename iterator_traits<_InputIter>::iterator_category _IterCategory;
    	_M_assign_aux(__first, __last, _IterCategory());
    }

	template <class _InputIterator>
	void 
	_M_assign_aux(_InputIterator __first, _InputIterator __last, input_iterator_tag);

	template <class _ForwardIterator>
	void 
	_M_assign_aux(_ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag);

  reference front() { return *begin(); }

  const_reference front() const { return *begin(); }

  reference back() { return *(end() - 1); }

  const_reference back() const { return *(end() - 1); }


  void push_back(const _Tp& __x)
  {
    if (this->__end_ != this->__end_cap_) {
		this->__a_.construct(this->__end_, __x);
      ++this->__end_;
    }
    else
      _M_insert_aux(end(), __x);
  }
  void swap(vector& x) 
  {
	 this->__swap_data(x); 
  }

  iterator insert(iterator __position, const _Tp& __x)
  {
    size_type __n = __position - begin();
    if (this->__end_ != this->__end_cap_ && __position == end()) {
      this->__a_.construct(this->__end_, __x);
      ++this->__end_;
    }
    else
      _M_insert_aux(iterator(__position), __x);
    return begin() + __n;
  }

  iterator insert(iterator __position)
  {
    size_type __n = __position - begin();
    if (this->__end_ != this->__end_cap_ && __position == end()) {
      this->__a_(this->__end_);
      ++this->__end_;
    }
    else
      _M_insert_aux(iterator(__position));
    return begin() + __n;
  }

  // Check whether it's an integral type.  If so, it's not an iterator.
  template<class _InputIterator>
    void
	insert(iterator __pos, _InputIterator __first, _InputIterator __last)
	{
      typedef typename is_integral<_InputIterator>::type _Integral;
      _M_insert_dispatch(__pos, __first, __last, _Integral());
    }

  template <class _Integer>
    void
	_M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val, true_type)
    { _M_fill_insert(__pos, static_cast<size_type>(__n), static_cast<_Tp>(__val)); }

  template<class _InputIterator>
    void
	_M_insert_dispatch(iterator __pos,
                       _InputIterator __first, _InputIterator __last,
                       false_type)
	{
	  typedef typename iterator_traits<_InputIterator>::iterator_category _IterCategory;
      _M_range_insert(__pos, __first, __last, _IterCategory());
    }

  void insert (iterator __pos, size_type __n, const _Tp& __x)
    { _M_fill_insert(__pos, __n, __x); }

  void _M_fill_insert (iterator __pos, size_type __n, const _Tp& __x);

  void pop_back() {
    --this->__end_;
    _Destroy(this->__end_);
  }



  iterator erase(iterator __position) {
	difference_type __diff = __position - begin();
  	pointer __pointer = this->__begin_ + __diff;

	_Destroy(__pointer);
	std::uninitialized_copy(__pointer + 1, this->__end_, __pointer);
	this->__end_--;
	_Destroy(this->__end_);
	return (__position);
  }

  iterator erase(iterator __first, iterator __last) {
	if (__first > __last)
		__throw_length_error("vector: first bigger than last");
    iterator __i(std::uninitialized_copy(__last, end(), __first));
    _Destroy(__i, end());
    this->__end_ = this->__end_ - (__last - __first);
    return __first;
  }

  void resize(size_type __new_size, const _Tp& __x) {
    if (__new_size < size())
      erase(begin() + __new_size, end());
    else
      insert(end(), __new_size - size(), __x);
  }

  void resize(size_type __new_size) { resize(__new_size, _Tp()); }

  void clear() { erase(begin(), end()); }

protected:

  template <class _ForwardIterator>
  pointer _M_allocate_and_copy(size_type __n, _ForwardIterator __first,
                                               _ForwardIterator __last)
  {
    pointer __result = this->__a_.allocate(__n);
    try {
      std::uninitialized_copy(__first, __last, __result);
      return __result;
    }
    catch(...)
      {
		this->__a_.deallocate(__result, __n);
		throw std::runtime_error("runtime err");
      }
  }

  template <class _InputIterator>
  void _M_range_initialize(_InputIterator __first,
                           _InputIterator __last, input_iterator_tag)
  {
    for ( ; __first != __last; ++__first)
      push_back(*__first);
  }

  // This function is only called by the constructor.
  template <class _ForwardIterator>
  void _M_range_initialize(_ForwardIterator __first,
                           _ForwardIterator __last, forward_iterator_tag)
  {
    size_type __n = ft::distance(__first, __last);
    this->__begin_ = this->__a_.allocate(__n);
    this->__end_cap_ = this->__begin_ + __n;
    this->__end_ = std::uninitialized_copy(__first, __last, this->__begin_);
  }

  template <class _InputIterator>
  void _M_range_insert(iterator __pos,
                       _InputIterator __first, _InputIterator __last,
                       input_iterator_tag);

  template <class _ForwardIterator>
  void _M_range_insert(iterator __pos,
                       _ForwardIterator __first, _ForwardIterator __last,
                       forward_iterator_tag);
};

























template <class _Tp, class _Alloc>
inline bool
operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
{
  return __x.size() == __y.size() &&
         ft::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline bool
operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
{
  return ft::lexicographical_compare(__x.begin(), __x.end(),
                                 __y.begin(), __y.end());
}

template <class _Tp, class _Alloc>
inline void swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
{
  __x.swap(__y);
}

template <class _Tp, class _Alloc>
inline bool
operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool
operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool
operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline bool
operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__x < __y);
}













template <class _Tp, class _Alloc>
vector<_Tp,_Alloc>&
vector<_Tp,_Alloc>::operator=(const vector<_Tp, _Alloc>& __x)
{
  if (&__x != this) {
    const size_type __xlen = __x.size();
    if (__xlen > capacity()) {
      pointer __tmp = _M_allocate_and_copy(__xlen, __x.begin(), __x.end());
      _Destroy(this->__begin_, this->__end_);
      this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
      this->__begin_ = __tmp;
      this->__end_cap_ = this->__begin_ + __xlen;
    }
    else if (size() >= __xlen) {
      iterator __i(std::copy(__x.begin(), __x.end(), begin()));
      _Destroy(__i, end());
    }
    else {
      std::copy(__x.begin(), __x.begin() + size(), this->__begin_);
      std::uninitialized_copy(__x.begin() + size(), __x.end(), this->__end_);
    }
    this->__end_ = this->__begin_ + __xlen;
  }
  return *this;
}









template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_assign(size_t __n, const value_type& __val)
{
  if (__n > capacity()) {
    vector<_Tp, _Alloc> __tmp(__n, __val, get_allocator());
    __tmp.swap(*this);
  }
  else if (__n > size()) {
    std::fill(begin(), end(), __val);
    this->__end_ = std::uninitialized_fill_n(this->__end_, __n - size(), __val);
  }
  else
    erase(std::fill_n(begin(), __n, __val), end());
}

template <class _Tp, class _Alloc> template <class _InputIter>
void vector<_Tp, _Alloc>::_M_assign_aux(_InputIter __first, _InputIter __last,
                                        input_iterator_tag) {
  iterator __cur(begin());
  for ( ; __first != __last && __cur != end(); ++__cur, ++__first)
    *__cur = *__first;
  if (__first == __last)
    erase(__cur, end());
  else
    insert(end(), __first, __last);
}

template <class _Tp, class _Alloc> template <class _ForwardIter>
void
vector<_Tp, _Alloc>::_M_assign_aux(_ForwardIter __first, _ForwardIter __last,
                                   forward_iterator_tag) {
  size_type __len = ft::distance(__first, __last);

  if (__len > capacity()) {
    pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
    _Destroy(this->__begin_, this->__end_);
    this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
    this->__begin_ = __tmp;
    this->__end_cap_ = this->__end_ = this->__begin_ + __len;
  }
  else if (size() >= __len) {
    iterator __new_finish(std::copy(__first, __last, this->__begin_));
    _Destroy(__new_finish, end());
    this->__end_ = __new_finish.base();
  }
  else {
    _ForwardIter __mid = __first;
    std::advance(__mid, size());
    std::copy(__first, __mid, this->__begin_);
    this->__end_ = std::uninitialized_copy(__mid, __last, this->__end_);
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, const _Tp& __x)
{
  if (this->__end_ != this->__end_cap_) {
    this->__a_.construct(this->__end_, *(this->__end_ - 1));
    ++this->__end_;
    _Tp __x_copy = __x;
    std::copy_backward(__position, iterator(this->__end_ - 2), iterator(this->__end_- 1));
    *__position = __x_copy;
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    iterator __new_start(this->__a_.allocate(__len));
    iterator __new_finish(__new_start);
    try {
      __new_finish = std::uninitialized_copy(iterator(this->__begin_), __position,
                                        __new_start);
      this->__a_.construct(__new_finish.base(), __x);
      ++__new_finish;
      __new_finish = std::uninitialized_copy(__position, iterator(this->__end_),
                                        __new_finish);
    }
    catch(...)
      {
	_Destroy(__new_start,__new_finish);
	this->__a_.deallocate(__new_start.base(),__len);
	// __throw_exception_again;
	// throw std::
      }
    _Destroy(begin(), end());
    this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
    this->__begin_ = __new_start.base();
    this->__end_ = __new_finish.base();
    this->__end_cap_ = __new_start.base() + __len;
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position)
{
  if (this->__end_ != this->__end_cap_) {
    this->__a_.construct(this->__end_, *(this->__end_ - 1));
    ++this->__end_;
    std::copy_backward(__position, iterator(this->__end_ - 2),
		  iterator(this->__end_ - 1));
    *__position = _Tp();
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    pointer __new_start = this->__a_.allocate(__len);
    pointer __new_finish = __new_start;
    try {
      __new_finish = uninitialized_copy(iterator(this->__begin_), __position,
					__new_start);
      _Construct(__new_finish);
      ++__new_finish;
      __new_finish = uninitialized_copy(__position, iterator(this->__end_),
					__new_finish);
    }
    catch(...)
      {
	_Destroy(__new_start,__new_finish);
	this->__a_.deallocate(__new_start,__len);
	// __throw_exception_again;
      }
    _Destroy(begin(), end());
    this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
    this->__begin_ = __new_start;
    this->__end_ = __new_finish;
    this->__end_cap_ = __new_start + __len;
  }
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                         const _Tp& __x)
{
  if (__n != 0) {
    if (size_type(this->__end_cap_ - this->__end_) >= __n) {
      _Tp __x_copy = __x;
      const size_type __elems_after = end() - __position;
      iterator __old_finish(this->__end_);
      if (__elems_after > __n) {
        std::uninitialized_copy(this->__end_ - __n, this->__end_, this->__end_);
        this->__end_ += __n;
        std::copy_backward(__position, __old_finish - __n, __old_finish);
        std::fill(__position, __position + __n, __x_copy);
      }
      else {
        std::uninitialized_fill_n(this->__end_, __n - __elems_after, __x_copy);
        this->__end_ += __n - __elems_after;
        std::uninitialized_copy(__position, __old_finish, this->__end_);
        this->__end_ += __elems_after;
        std::fill(__position, __old_finish, __x_copy);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + std::max(__old_size, __n);
      iterator __new_start(this->__a_.allocate(__len));
      iterator __new_finish(__new_start);
      try {
        __new_finish = std::uninitialized_copy(begin(), __position, __new_start);
        __new_finish = std::uninitialized_fill_n(__new_finish, __n, __x);
        __new_finish
          = std::uninitialized_copy(__position, end(), __new_finish);
      }
      catch(...)
	{
	  _Destroy(__new_start,__new_finish);
	  this->__a_.deallocate(__new_start.base(),__len);
	  //__throw_exception_again;
	}
      _Destroy(this->__begin_, this->__end_);
      this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
      this->__begin_ = __new_start.base();
      this->__end_ = __new_finish.base();
      this->__end_cap_ = __new_start.base() + __len;
    }
  }
}

template <class _Tp, class _Alloc> template <class _InputIterator>
void
vector<_Tp, _Alloc>::_M_range_insert(iterator __pos,
                                     _InputIterator __first,
                                     _InputIterator __last,
                                     input_iterator_tag)
{
  for ( ; __first != __last; ++__first) {
    __pos = insert(__pos, *__first);
    ++__pos;
  }
}

template <class _Tp, class _Alloc> template <class _ForwardIterator>
void
vector<_Tp, _Alloc>::_M_range_insert(iterator __position, _ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag) {
  if (__first != __last) {
    size_type __n = ft::distance(__first, __last);
    if (size_type(this->__end_cap_ - this->__end_) >= __n) {
      const size_type __elems_after = end() - __position;
      iterator __old_finish(this->__end_);
      if (__elems_after > __n) {
        std::uninitialized_copy(this->__end_ - __n, this->__end_, this->__end_);
        this->__end_ += __n;
        std::copy_backward(__position, __old_finish - __n, __old_finish);
        std::copy(__first, __last, __position);
      }
      else {
        _ForwardIterator __mid = __first;
        std::advance(__mid, __elems_after); // 개발 해야 함
        std::uninitialized_copy(__mid, __last, this->__end_);
        this->__end_ += __n - __elems_after;
        std::uninitialized_copy(__position, __old_finish, this->__end_);
        this->__end_ += __elems_after;
        std::copy(__first, __mid, __position);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + std::max(__old_size, __n);
      iterator __new_start(this->__a_.allocate(__len));
      iterator __new_finish(__new_start);
      try {
        __new_finish = std::uninitialized_copy(iterator(this->__begin_), __position, __new_start);
        __new_finish = std::uninitialized_copy(__first, __last, __new_finish);
        __new_finish = std::uninitialized_copy(__position, iterator(this->__end_), __new_finish);
      }
      catch(...)
	{
	  _Destroy(__new_start,__new_finish);
	}
      _Destroy(this->__begin_, this->__end_);
      this->__a_.deallocate(this->__begin_, this->__end_cap_ - this->__begin_);
      this->__begin_ = __new_start.base();
      this->__end_ = __new_finish.base();
      this->__end_cap_ = __new_start.base() + __len;
    }
  }
}


}

#endif

