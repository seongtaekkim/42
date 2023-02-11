
#ifndef ITERATOR_BASE_FUNC_HPP
#define ITERATOR_BASE_FUNC_HPP

#include <iostream>
#include "iterator_base_type.hpp"

namespace ft
{

template<typename _InputIterator>
	inline typename iterator_traits<_InputIterator>::difference_type
	__distance(_InputIterator __first, _InputIterator __last, input_iterator_tag)
	{
		//    __glibcpp_function_requires(_InputIteratorConcept<_InputIterator>)

		typename iterator_traits<_InputIterator>::difference_type __n = 0;
		while (__first != __last) {
			++__first;
			++__n;
		}
		return (__n);
	}

template<typename _RandomAccessIterator>
	inline typename iterator_traits<_RandomAccessIterator>::differnce_type
	__distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
				random_access_iterator_tag)
	{
		//    __glibcpp_function_requires(_RandomAccessIteratorConcept<_RandomAccessIterator>)
		return (__last - __first);
	}


template<typename _InputIterator>
	inline typename iterator_traits<_InputIterator>::difference_type
	distance(_InputIterator __first, _InputIterator __last)
	{
		return __distance(__first, __last, __iterator_category(__first));
	}
	


} // namespace ft

#endif