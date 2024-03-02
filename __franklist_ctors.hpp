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

    head = new Node();
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tail->next = new Node();
        tail->prev = tail;
        tail = tail->next;
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

    head = new Node(init);
    tail = head;

    for (int i = 1; i < size; i++)
    {
        tail->next = new Node(init);
        tail->prev = tail;
        tail = tail->next;
    }
}

template <typename T>
FrankList<T>::FrankList(const FrankList<value_type>& rhv)

    : head{new Node(rhv.head->val)},
    tail{head},
    ahead{nullptr},
    atail{nullptr}
{
    for (auto i = ++rhv.cbegin(); i != rhv.cend(); i++)
    {
        tail->next = new Node(*i);
        tail->prev = tail;
        tail = tail->next;       
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

    : head{new Node(*init.begin())},
    tail{head},
    ahead{nullptr},
    atail{nullptr} 
{

    for (auto i = init.begin() + 1; i != init.end(); i++)
    {
        tail->next = new Node(*i);
        tail->prev = tail;
        tail = tail->next;
    }
}


template <class T> 
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)

    : ahead{nullptr},
    atail{nullptr}
{
    if (!std::is_base_of<base_iterator, input_iterator>::value && 
    !std::is_same<base_iterator, input_iterator>::value)
    {
        throw std::invalid_argument("Ivalid iterator type");
    }

    head = new Node(*f);
    tail = head;

    for (FrankList<T>::const_iterator i = ++f; i != l; i++)
    {
        tail->next = new Node(*i);
        tail->prev = tail;
        tail = tail->next;
    }
}


#endif // __FRANKLIST_CTORS_HPP__