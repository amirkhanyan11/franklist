#ifndef __ITERATORS_HPP__
#define __ITERATORS_HPP__

#include "franklist.h"
#include "__const_iterator.hpp"
#include "__iterator.hpp"
#include "__const_reverse_iterator.hpp"
#include "__reverse_iterator.hpp"
#include "__const_asc_iterator.hpp"
#include "__asc_iterator.hpp"
#include "__const_desc_iterator.hpp"
#include "__desc_iterator.hpp"
#include "__const_multi_iterator.hpp"
#include "__multi_iterator.hpp"
#include "__const_multi_reverse_iterator.hpp"
#include "__multi_reverse_iterator.hpp"

#include "__member_iterator_methods.hpp"

// BASE ITERATOR
template <typename T>
bool FrankList<T>::base_iterator::operator== (const FrankList<T>::base_iterator& rhv) const
{
    return (this->ptr == rhv.ptr);
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
std::string FrankList<T>::base_iterator::error_message(const std::type_info& info, char const * const func) const
{
    std::string error_class = info.name();
    std::string message = error_class + "::" + func + " attempted to dereference a nullptr\n";
	return std::move(message);
}


#endif // __ITERATORS_HPP__
