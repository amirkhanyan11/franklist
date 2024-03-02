
#include "franklist.h"

using namespace vhuk;


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
    return (const_cast<reference>(*static_cast<const_iterator*>(*this)));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator->()
{
    return (const_cast<pointer>((static_cast<const_iterator*>(*this))->operator->));
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
	*(static_cast<const_iterator*>(this)) = rhv;

    return (*this);
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(base_iterator&& rhv)
{
	*(static_cast<const_iterator*>(this)) = rhv;

    return (*this);
}

template <typename T>
FrankList<T>::iterator::iterator(Node* ptr)
{
    this->ptr = ptr;
}
