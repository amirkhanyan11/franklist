#ifndef __DESC_ITERATOR_HPP__
#define __DESC_ITERATOR_HPP__

#include "franklist.h"

using namespace vhuk;


template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv)
{
	this->ptr = ptr;
}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv)
{
	this->ptr = ptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
{
	return (const_cast<reference>(*static_cast<const_desc_iterator*>(this)));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
{
	return (const_cast<pointer>((static_cast<const_desc_iterator*>(this))->operator->));
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(const base_iterator& rhv)
{
	*(static_cast<const_desc_iterator*>(this)) = rhv;

    return (*this);
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(base_iterator&& rhv)
{
	*(static_cast<const_desc_iterator*>(this)) = rhv;

    return (*this);
}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* ptr)
{
	this->ptr = ptr;
}

#endif // __DESC_ITERATOR_HPP__
