
#include "franklist.h"
#include "const_iterator.hpp"

// BASE ITERATOR
template <typename T>
bool FrankList<T>::base_iterator::operator== (const FrankList<T>::base_iterator& rhv) const
{
    return (this->ptr == rhv->ptr);
}

template <typename T>
bool FrankList<T>::base_iterator::operator!= (const FrankList<T>::base_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr)

    : ptr{ptr} {}

template <typename T>
FrankList<T>::base_iterator::~base_iterator() = default;











template <typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::iterator::operator*()
{
    return *(this->ptr);
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator->()
{
    return (this->ptr);
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
    return (*this = std::move(rhv));
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
    if (this != &rhv)
        this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
FrankList<T>::iterator::iterator(Node* ptr)
{
    this->ptr = ptr;
}

