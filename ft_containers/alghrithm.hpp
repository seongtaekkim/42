
#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{

/*
while 로 변경하기
*/
template<typename InIterator1, typename InIterator2>
bool lexicographical_compare(InIterator1 first1, InIterator1 last1, InIterator2 first2, InIterator2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (*first1 < *first2)
            return (true);
        if (*first2 < *first1)
            return (false);
    } 
    return ((first1 == last1) && (first2 != last2));
}

template<typename InIterator1, typename InIterator2, typename Compare>
bool lexicographical_compare(InIterator1 first1, InIterator1 last1, InIterator2 first2, InIterator2 last2, Compare comp)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (comp(*first1, *first2))
            return (true);
        if (comp(*first2, *first1))
            return (false);
	}
    return (first1 == last1) && (first2 != last2);
}


template<typename InIterator1, typename InIterator2>
const bool equal(InIterator1 first1, InIterator1 last1, InIterator2 first2)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!(*first1 == *first2))
            return false;
 
    return true;
}

/*
const 붙여야 하나 ?????????????
*/
template<typename InIterator1, typename InIterator2, typename BinaryPredicate>
const bool equal(InIterator1 first1, InIterator1 last1, InIterator2 first2, BinaryPredicate p)
{
    for (; first1 != last1; ++first1, ++first2)
        if (!p(*first1, *first2))
            return (false);
    return (true);
}

}

#endif