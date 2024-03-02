#ifndef __FRANKLIST_HPP_IMPL__
#define __FRANKLIST_HPP_IMPL__

#include <stdexcept>
#include "node.hpp"
#include "iterators.hpp"
#include "__franklist_ctors.hpp"



template <typename T>
void FrankList<T>::swap(FrankList<value_type>& rhv)
{
    FrankList<T> tmp = std::move(*this);
    this = std::move(rhv);
    rhv = std::move(tmp);
}

template <typename T>
bool FrankList<T>::empty() const
{
    return (head == nullptr);
}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::size() const
{
    size_type lstsize = 0;

    for (FrankList<T>::const_iterator i = this->cbegin(); i != this->cend(); i++)
        lstsize++;

    return (lstsize);
}


template <typename T>
void FrankList<T>::clear() noexcept
{
    for (Node* i = this->head; i != nullptr; )
    {
        auto tmp = i->next;
        delete i;
        i = tmp;
    }
}

template <typename T>
void FrankList<T>::resize(size_type s, const_reference init)
{
    this->clear();
    *this = FrankList<T>(s, init);
}


template <typename T>
const FrankList<T>& FrankList<T>::operator=(const FrankList<T>& rhv)
{
    *this = FrankList<T>(rhv);
    return *this;
}


template <typename T>
const FrankList<T>& FrankList<T>::operator=(FrankList<T>&& rhv)
{
    if (this != &rhv)
    {
        this->clear();
        this->head = rhv.head;
        this->tail = rhv.tail;
        this->ahead = rhv.ahead;
        this->atail = rhv.atail;

        rhv.head = nullptr;
        rhv.tail = nullptr;
        rhv.ahead = nullptr;
        rhv.atail = nullptr;
    }
    return *this;
}

template <typename T>
const FrankList<T>& FrankList<T>::operator=(std::initializer_list<T> init)
{
    *this = FrankList<T>(init);
    return *this;
}




template <typename T>
void FrankList<T>::push_front(const_reference elem)
{
    if (head == nullptr)
    {
        head = new Node(elem);
        tail = head;
    }
    else
    {
        Node* tmp = new Node(elem);
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}


template <typename T>
void FrankList<T>::pop_front()
{
    if (head == nullptr)
        return;

    Node* tmp = head;

    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    if (tail == tmp)
        tail = head;

    delete tmp;
}


#endif // __FRANKLIST_HPP_IMPL__
