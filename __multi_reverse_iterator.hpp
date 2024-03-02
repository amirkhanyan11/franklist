


#include "franklist.h"

using namespace vhuk;


template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv)
{
    this->ptr = rhv->ptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::multi_reverse_iterator::operator*()
{
    return (const_cast<reference>(*static_cast<const_multi_reverse_iterator*>(this)));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::multi_reverse_iterator::operator->()
{
    return (const_cast<pointer>((static_cast<const_multi_reverse_iterator*>(this))->operator->));
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    *(static_cast<const_multi_reverse_iterator*>this) = rhv;

	return(*this);
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    *(static_cast<const_multi_reverse_iterator*>this) = rhv;

	return(*this);
}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* ptr)
{
    this->ptr = ptr;
}
