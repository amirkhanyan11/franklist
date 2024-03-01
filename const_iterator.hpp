
#include "franklist.h"

using namespace vhuk;


template <typename T>
FrankList<T>::const_iterator::const_iterator(Node* ptr)
{
    this->ptr = ptr;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv)
{
    this->ptr = rhv->ptr;
}


template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_iterator::operator*() const
{
    return *(this->ptr);
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_iterator::operator->() const
{
    return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++()
{
    this->ptr = this->ptr->next;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
{
    FrankList::Node* tmp = this->ptr;

    ++(*this);

    return (base_iterator(tmp));
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    this->ptr = this->ptr->prev;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
{
    FrankList::Node* tmp = this->ptr;

    --(*this);

    return (base_iterator(tmp));
}