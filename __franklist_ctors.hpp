#ifndef __FRANKLIST_CTORS_HPP__
#define __FRANKLIST_CTORS_HPP__

#include <stdexcept>
#include "node.hpp"
#include "iterators.hpp"

template <typename T>
FrankList<T>::FrankList()

    : head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr} {}

template <typename T>
FrankList<T>::FrankList(size_type size)

    : head {nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{

    if (size == 0)
    {
        throw std::invalid_argument("Invalid size of 0");
    }

    for (int i = 0; i < size; i++)
    {
        this->push_back(T{});
    }
}

template <typename T>
FrankList<T>::FrankList(size_type size, const_reference init)

    : head {nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{

    if (size == 0)
    {
        throw std::invalid_argument("Invalid size of 0");
    }

    for (int i = 0; i < size; i++)
    {
        this->push_back(init);
    }
}

template <typename T>
FrankList<T>::FrankList(const FrankList<value_type>& rhv)

    : head{nullptr},
    tail{head},
    ahead{head},
    atail{head}
{
    for (auto i = ++rhv.cbegin(); i != rhv.cend(); i++)
    {
        this->push_back(*i);
    }
}

template <typename T>
FrankList<T>::FrankList(FrankList<value_type>&& rhv)

    : head{rhv.head},
    tail{rhv.tail},
    ahead{rhv.ahead},
    atail{rhv.atail}
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}


template <typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init)

    : head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{

    for (auto i = init.begin(); i != init.end(); i++)
    {
        this->push_back(*i);
    }
}


template <class T>
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)

    : head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{
    if (!std::is_base_of<base_iterator, input_iterator>::value &&
    !std::is_same<base_iterator, input_iterator>::value)
    {
        throw std::invalid_argument("Ivalid iterator type");
    }

    if (f != l)
    {

        for (auto i = f; i != l; i++)
        {
            this->push_back(*i);
        }
    }
}


template <typename T>
FrankList<T>::~FrankList()
{
    this->clear();
}


#endif // __FRANKLIST_CTORS_HPP__
