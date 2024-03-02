#ifndef __CONST_MULTI_REVERSE_ITERATOR_HPP__
#define __CONST_MULTI_REVERSE_ITERATOR_HPP__


#include "franklist.h"

using namespace vhuk;


template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator&  FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    return (*this = std::move(rhv));
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator&  FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    if (this != &rhv)
        this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_multi_reverse_iterator::operator*() const
{
    return *(this->ptr);
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_multi_reverse_iterator::operator->() const
{
    return (this->ptr);
}



template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator++()
{
    this->ptr = (mode == true) ? this->ptr->prev : this->ptr->next;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator++(value_type)
{
    FrankList::Node* tmp = this->ptr;

    --(*this);

    return (base_iterator(tmp));
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator--()
{
    this->ptr = (mode == true) ? this->ptr->next : this->ptr->prev;

	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator--(value_type)
{
    FrankList::Node* tmp = this->ptr;

    ++(*this);

    return (base_iterator(tmp));
}


template <typename T>
void FrankList<T>::const_multi_reverse_iterator::chmod()
{
	mode = !mode;
}


template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr)
{
    this->ptr = ptr;
}

#endif // __CONST_MULTI_REVERSE_ITERATOR_HPP__
