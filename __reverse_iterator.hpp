
#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include "franklist.h"

using namespace vhuk;


template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv)

	: const_reverse_iterator(rhv){}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv)

	: const_reverse_iterator(rhv){}

template <typename T>
typename FrankList<T>::reference FrankList<T>::reverse_iterator::operator*()
{
	return (const_cast<reference>((static_cast<const_reverse_iterator*>(*this)->operator*())));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::reverse_iterator::operator->()
{
	return (const_cast<pointer>((static_cast<const_reverse_iterator*>(*this)->operator->())));
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv)
{
    *(static_cast<const_reverse_iterator*>(this)) = rhv;

	return (*this);
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv)
{
    *(static_cast<const_reverse_iterator*>(this)) = rhv;

	return (*this);
}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr)
{
	this->ptr = ptr;
}

#endif // __REVERSE_ITERATOR_HPP__
