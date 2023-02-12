
#ifndef VECTOR
#define VECTOR

#include <iostream>
#include "iterator_base_type.hpp"
#include "iterator_base_func.hpp"
#include "./type_traits.hpp"
#include "iterator.hpp"


namespace ft
{
/*
template <class _Tp, class _Allocator, bool _IsStatic>
class _Vector_alloc_base {
public:
	typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
	allocator_type get_allocator() const { return _M_data_allocator; }
	_Vector_alloc_base(const allocator_type& __a)
		: _M_data_allocator(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0)
	{}
	
protected:
  allocator_type _M_data_allocator;
  _Tp* _M_start;
  _Tp* _M_finish;
  _Tp* _M_end_of_storage;

  _Tp* _M_allocate(size_t __n)
    { return _M_data_allocator.allocate(__n); }
  void _M_deallocate(_Tp* __p, size_t __n)
    { if (__p) _M_data_allocator.deallocate(__p, __n); }
};

// Specialization for allocators that have the property that we don't
// actually have to store an allocator object.
template <class _Tp, class _Allocator>
class _Vector_alloc_base<_Tp, _Allocator, true> {
public:
  typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
  allocator_type get_allocator() const { return allocator_type(); }
  _Vector_alloc_base(const allocator_type&)
    : _M_start(0), _M_finish(0), _M_end_of_storage(0)
  {}

protected:
  _Tp* _M_start;
  _Tp* _M_finish;
  _Tp* _M_end_of_storage;

  typedef typename _Alloc_traits<_Tp, _Allocator>::_Alloc_type _Alloc_type;
  _Tp* _M_allocate(size_t __n)
    { return _Alloc_type::allocate(__n); }
  void _M_deallocate(_Tp* __p, size_t __n)
    { _Alloc_type::deallocate(__p, __n);}
};

template <class _Tp, class _Alloc>
struct _Vector_base : public _Vector_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
{
  typedef _Vector_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::_S_instanceless> _Base;
  typedef typename _Base::allocator_type allocator_type;

  _Vector_base(const allocator_type& __a) : _Base(__a) {}
  _Vector_base(size_t __n, const allocator_type& __a) : _Base(__a) {
    _M_start = _M_allocate(__n);
    _M_finish = _M_start;
    _M_end_of_storage = _M_start + __n;
  }
b 
  ~_Vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }
};
*/

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


// This iterator adapter is @a normal in the sense that it does not
// change the semantics of any of the operators of its iterator
// parameter.  Its primary purpose is to convert an iterator that is
// not a class, e.g. a pointer, into an iterator that is a class.
// The _Container parameter exists solely so that different containers
// using this template can instantiate different types, even if the
// _Iterator parameter is the same.
template<typename _Iterator, typename _Container>
class __normal_iterator
{
protected:
	_Iterator _M_current;
	typedef ft::iterator_traits<_Iterator>				__traits_type;

public:
	typedef _Iterator									iterator_type;
	typedef typename __traits_type::iterator_category	iterator_category;
	typedef typename __traits_type::value_type  		value_type;
	typedef typename __traits_type::difference_type 	difference_type;
	typedef typename __traits_type::reference 			reference;
	typedef typename __traits_type::pointer   			pointer;


	const __normal_iterator() throw()
	: _M_current(_Iterator()) {}

	__normal_iterator(const _Iterator& __i) throw()
	: _M_current(__i) {}

	// Allow iterator to const_iterator conversion
	template<typename _Iter>
	__normal_iterator(const __normal_iterator<_Iter,
			typename ft::enable_if<(std::__are_same<_Iter
								, typename _Container::pointer>::__value), _Container>::__type>& __i) throw()
	: _M_current(__i.base()) { }

	// Forward iterator requirements
	reference operator*() const throw()
	{ return *_M_current; }

	pointer operator->() const throw()
	{ return _M_current; }

	__normal_iterator& operator++() throw()
	{
		++_M_current;
		return *this;
	}

	__normal_iterator operator++(int) throw()
	{
		return __normal_iterator(_M_current++);
	}

	// Bidirectional iterator requirements
	__normal_iterator& operator--() throw()
	{
		--_M_current;
		return *this;
	}

	__normal_iterator operator--(int) throw()
	{ return __normal_iterator(_M_current--); }

	// Random access iterator requirements
	reference operator[](difference_type __n) const throw()
	{ return _M_current[__n]; }

	__normal_iterator& operator+=(difference_type __n) throw()
	{ _M_current += __n; return *this; }

	__normal_iterator operator+(difference_type __n) const throw()
	{ return __normal_iterator(_M_current + __n); }

	__normal_iterator& operator-=(difference_type __n) throw()
	{ _M_current -= __n; return *this; }

	__normal_iterator operator-(difference_type __n) const throw()
	{ return __normal_iterator(_M_current - __n); }

	const _Iterator& base() const throw()
	{ return _M_current; }
};


















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
  typedef __normal_iterator<pointer, vector_type> 		iterator;
  typedef __normal_iterator<const_pointer, vector_type>	const_iterator;
  typedef value_type& 									reference;
  typedef const value_type& 							const_reference;
  typedef size_t 										size_type;
  typedef ptrdiff_t 									difference_type;

  typedef reverse_iterator<const_iterator>				const_reverse_iterator;
  typedef reverse_iterator<iterator>					reverse_iterator;

  typedef typename _Base::allocator_type				allocator_type;
//   allocator_type get_allocator() const { return _Base::get_allocator(); }

protected:
//   using _Base::_M_allocate;
//   using _Base::_M_deallocate;
//   using _Base::_M_start;
//   using _Base::_M_finish;
//   using _Base::_M_end_of_storage;

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
	_M_finish = uninitialized_fill_n(this->__begin_, __n, __value);
  }

  explicit vector(size_type __n) : _Base(__n, allocator_type()) {
  	_M_finish = uninitialized_fill_n(_M_start, __n, _Tp());
  }

// 지우셈
  vector(const vector<_Tp, _Alloc>& __x)
    : _Base(__x.size(), __x.get_allocator())
    { _M_finish = uninitialized_copy(__x.begin(), __x.end(), _M_start); }

  // Check whether it's an integral type.  If so, it's not an iterator.
  template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type())
	: _Base(__a)
	{
      typedef typename is_integral<_InputIterator>::_Integral _Integral;
      _M_initialize_aux(__first, __last, _Integral());
    }

  template <class _Integer>
    void _M_initialize_aux(_Integer __n, _Integer __value, true_type)
	{
      _M_start = _M_allocate(__n);
      _M_end_of_storage = _M_start + __n;
      _M_finish = uninitialized_fill_n(_M_start, __n, __value);
    }

  template<class _InputIterator>
    void
	_M_initialize_aux(_InputIterator __first, _InputIterator __last, false_type)
	{
	  typedef typename iterator_traits<_InputIterator>::iterator_category _IterCategory;
	  _M_range_initialize(__first, __last, _IterCategory());
	}

  ~vector() {
	_Destroy(this->__begin_, _M_finish);
  }









  vector<_Tp, _Alloc>& operator=(const vector<_Tp, _Alloc>& __x);

  void reserve(size_type __n) {
    if (capacity() < __n) {
      const size_type __old_size = size();
      pointer __tmp = _M_allocate_and_copy(__n, _M_start, _M_finish);
      _Destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __tmp;
      _M_finish = __tmp + __old_size;
      _M_end_of_storage = _M_start + __n;
    }
  }


  void assign(size_type __n, const _Tp& __val) { _M_fill_assign(__n, __val); }
  void _M_fill_assign(size_type __n, const _Tp& __val);

  template<class _InputIterator>
    void
    assign(_InputIterator __first, _InputIterator __last)
    {
      typedef typename is_integral<_InputIterator>::_Integral _Integral;
      _M_assign_dispatch(__first, __last, _Integral());
    }

  template<class _Integer>
    void
     _M_assign_dispatch(_Integer __n, _Integer __val, true_type)
     { _M_fill_assign((size_type) __n, (_Tp) __val); }

  template<class _InputIter>
    void
    _M_assign_dispatch(_InputIter __first, _InputIter __last, false_type)
    {
      typedef typename iterator_traits<_InputIter>::iterator_category _IterCategory;
      _M_assign_aux(__first, __last, _IterCategory());
    }

  template <class _InputIterator>
    void 
    _M_assign_aux(_InputIterator __first, _InputIterator __last,
		  input_iterator_tag);

  template <class _ForwardIterator>
    void 
    _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
		  forward_iterator_tag);

  reference front() { return *begin(); }

  const_reference front() const { return *begin(); }

  reference back() { return *(end() - 1); }

  const_reference back() const { return *(end() - 1); }


  void push_back(const _Tp& __x)
  {
    if (_M_finish != _M_end_of_storage) {
		this->__a_.construct(this->__end_, __x);
      	//_Construct(this->__end_, __x);
      ++_M_finish;
    }
    else
      _M_insert_aux(end(), __x);
  }

  void swap(vector<_Tp, _Alloc>& __x)
  {
    std::swap(_M_start, __x._M_start);
    std::swap(_M_finish, __x._M_finish);
    std::swap(_M_end_of_storage, __x._M_end_of_storage);
  }

  iterator insert(iterator __position, const _Tp& __x)
  {
    size_type __n = __position - begin();
    if (_M_finish != _M_end_of_storage && __position == end()) {
      _Construct(_M_finish, __x);
      ++_M_finish;
    }
    else
      _M_insert_aux(iterator(__position), __x);
    return begin() + __n;
  }

  iterator insert(iterator __position)
  {
    size_type __n = __position - begin();
    if (_M_finish != _M_end_of_storage && __position == end()) {
      _Construct(_M_finish);
      ++_M_finish;
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
      typedef typename is_integral<_InputIterator>::_Integral _Integral;
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
    --_M_finish;
    _Destroy(_M_finish);
  }

  template <class _Tp>
  void _Destroy(_Tp *_pointer){
	_pointer->~_Tp();
  }

  void _Destroy(iterator _first, iterator _last) {
	iterator it = _first;
	for (; it!=_last; ++it){
		this.__a_.destroy(&(*it));
	}
  }



  iterator erase(iterator __position) {
    if (__position + 1 != end())
      copy(__position + 1, end(), __position);
    --_M_finish;
    _Destroy(_M_finish);
    return __position;
  }

  iterator erase(iterator __first, iterator __last) {
    iterator __i(copy(__last, end(), __first));
    _Destroy(__i, end());
    _M_finish = _M_finish - (__last - __first);
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
    pointer __result = _M_allocate(__n);
    try {
      std::uninitialized_copy(__first, __last, __result);
      return __result;
    }
    catch(...)
      {
		_M_deallocate(__result, __n);
		// __throw_exception_again;
		throw std::exception("");
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
    size_type __n = distance(__first, __last);
    _M_start = _M_allocate(__n);
    _M_end_of_storage = _M_start + __n;
    _M_finish = uninitialized_copy(__first, __last, _M_start);
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
         equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline bool
operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
{
  return lexicographical_compare(__x.begin(), __x.end(),
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
      _Destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __tmp;
      _M_end_of_storage = _M_start + __xlen;
    }
    else if (size() >= __xlen) {
      iterator __i(copy(__x.begin(), __x.end(), begin()));
      _Destroy(__i, end());
    }
    else {
      copy(__x.begin(), __x.begin() + size(), _M_start);
      uninitialized_copy(__x.begin() + size(), __x.end(), _M_finish);
    }
    _M_finish = _M_start + __xlen;
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
    fill(begin(), end(), __val);
    _M_finish = uninitialized_fill_n(_M_finish, __n - size(), __val);
  }
  else
    erase(fill_n(begin(), __n, __val), end());
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
  size_type __len = distance(__first, __last);

  if (__len > capacity()) {
    pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
    _Destroy(_M_start, _M_finish);
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __tmp;
    _M_end_of_storage = _M_finish = _M_start + __len;
  }
  else if (size() >= __len) {
    iterator __new_finish(copy(__first, __last, _M_start));
    _Destroy(__new_finish, end());
    _M_finish = __new_finish.base();
  }
  else {
    _ForwardIter __mid = __first;
    advance(__mid, size());
    copy(__first, __mid, _M_start);
    _M_finish = uninitialized_copy(__mid, __last, _M_finish);
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, const _Tp& __x)
{
  if (_M_finish != _M_end_of_storage) {
    _Construct(_M_finish, *(_M_finish - 1));
    ++_M_finish;
    _Tp __x_copy = __x;
    copy_backward(__position, iterator(_M_finish - 2), iterator(_M_finish- 1));
    *__position = __x_copy;
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    iterator __new_start(_M_allocate(__len));
    iterator __new_finish(__new_start);
    try {
      __new_finish = uninitialized_copy(iterator(_M_start), __position,
                                        __new_start);
      _Construct(__new_finish.base(), __x);
      ++__new_finish;
      __new_finish = uninitialized_copy(__position, iterator(_M_finish),
                                        __new_finish);
    }
    catch(...)
      {
	_Destroy(__new_start,__new_finish);
	_M_deallocate(__new_start.base(),__len);
	__throw_exception_again;
      }
    _Destroy(begin(), end());
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __new_start.base();
    _M_finish = __new_finish.base();
    _M_end_of_storage = __new_start.base() + __len;
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position)
{
  if (_M_finish != _M_end_of_storage) {
    _Construct(_M_finish, *(_M_finish - 1));
    ++_M_finish;
    copy_backward(__position, iterator(_M_finish - 2),
		  iterator(_M_finish - 1));
    *__position = _Tp();
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    pointer __new_start = _M_allocate(__len);
    pointer __new_finish = __new_start;
    try {
      __new_finish = uninitialized_copy(iterator(_M_start), __position,
					__new_start);
      _Construct(__new_finish);
      ++__new_finish;
      __new_finish = uninitialized_copy(__position, iterator(_M_finish),
					__new_finish);
    }
    catch(...)
      {
	_Destroy(__new_start,__new_finish);
	_M_deallocate(__new_start,__len);
	__throw_exception_again;
      }
    _Destroy(begin(), end());
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __new_start;
    _M_finish = __new_finish;
    _M_end_of_storage = __new_start + __len;
  }
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                         const _Tp& __x)
{
  if (__n != 0) {
    if (size_type(_M_end_of_storage - _M_finish) >= __n) {
      _Tp __x_copy = __x;
      const size_type __elems_after = end() - __position;
      iterator __old_finish(_M_finish);
      if (__elems_after > __n) {
        uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
        _M_finish += __n;
        copy_backward(__position, __old_finish - __n, __old_finish);
        fill(__position, __position + __n, __x_copy);
      }
      else {
        std::uninitialized_fill_n(_M_finish, __n - __elems_after, __x_copy);
        _M_finish += __n - __elems_after;
        std::uninitialized_copy(__position, __old_finish, _M_finish);
        _M_finish += __elems_after;
        fill(__position, __old_finish, __x_copy);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + max(__old_size, __n);
      iterator __new_start(_M_allocate(__len));
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
	  _M_deallocate(__new_start.base(),__len);
	  __throw_exception_again;
	}
      _Destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __new_start.base();
      _M_finish = __new_finish.base();
      _M_end_of_storage = __new_start.base() + __len;
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
vector<_Tp, _Alloc>::_M_range_insert(iterator __position,
                                     _ForwardIterator __first,
                                     _ForwardIterator __last,
                                     forward_iterator_tag)
{
  if (__first != __last) {
    size_type __n = distance(__first, __last);
    if (size_type(_M_end_of_storage - _M_finish) >= __n) {
      const size_type __elems_after = end() - __position;
      iterator __old_finish(_M_finish);
      if (__elems_after > __n) {
        uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
        _M_finish += __n;
        copy_backward(__position, __old_finish - __n, __old_finish);
        copy(__first, __last, __position);
      }
      else {
        _ForwardIterator __mid = __first;
        advance(__mid, __elems_after);
        uninitialized_copy(__mid, __last, _M_finish);
        _M_finish += __n - __elems_after;
        uninitialized_copy(__position, __old_finish, _M_finish);
        _M_finish += __elems_after;
        copy(__first, __mid, __position);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + max(__old_size, __n);
      iterator __new_start(_M_allocate(__len));
      iterator __new_finish(__new_start);
      try {
        __new_finish = uninitialized_copy(iterator(_M_start),
					  __position, __new_start);
        __new_finish = uninitialized_copy(__first, __last, __new_finish);
        __new_finish
          = uninitialized_copy(__position, iterator(_M_finish), __new_finish);
      }
      catch(...)
	{
	  _Destroy(__new_start,__new_finish);
	  _M_deallocate(__new_start.base(), __len);
	  __throw_exception_again;
	}
      _Destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __new_start.base();
      _M_finish = __new_finish.base();
      _M_end_of_storage = __new_start.base() + __len;
    }
  }
}


}

#endif