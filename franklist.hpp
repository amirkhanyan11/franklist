#ifndef __FRANKLIST_HPP_IMPL__
#define __FRANKLIST_HPP_IMPL__

#include <stdexcept>
#include "node.hpp"
#include "iterators.hpp"
#include "__franklist_ctors.hpp"


template <typename T>
bool FrankList<T>::empty() const
{
    return (head == nullptr);
}


template <typename T>
typename FrankList<T>::size_type FrankList<T>::size() const
{
    size_type lstsize = 0;

    for (auto i : *this)
        lstsize++;

    return (lstsize);
}


template <typename T>
void FrankList<T>::clear() noexcept
{
    for (Node* i = this->head; i != nullptr; )
    {
        auto tmp = ++i;
        delete i;
        i = tmp;
    }
}

template <typename T>
FrankList<T>::~FrankList()
{
    this->clear();
	std::cout << "mah" << std::endl;

}


#endif // __FRANKLIST_HPP_IMPL__    