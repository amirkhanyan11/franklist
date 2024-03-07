#ifndef __CONST_ASC_ITERATOR_HPP__
#define __CONST_ASC_ITERATOR_HPP__

#include "franklist.h"

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv)

	: base_iterator(rhv.ptr){}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv)

	: base_iterator(rhv.ptr){}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr)

	: base_iterator(ptr){}


template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv)
{
    return (*this = std::move(rhv));
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(base_iterator&& rhv)
{
    if (this != &rhv)
        this->ptr = rhv.ptr;
    return (*this);
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
{
	return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{
	this->ptr = this->ptr->asc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(int)
{
    FrankList::Node* tmp = this->ptr;

	++(*this);

	return (base_iterator(tmp));
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
	this->ptr = this->ptr->desc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(int)
{
    FrankList::Node* tmp = this->ptr;

	++(*this);

	return (base_iterator(tmp));
}

#endif // __CONST_ASC_ITERATOR_HPP__
