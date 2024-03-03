#ifndef __FRANKLIST_HPP_IMPL__
#define __FRANKLIST_HPP_IMPL__

#include <stdexcept>
#include "node.hpp"
#include "iterators.hpp"
#include "__franklist_ctors.hpp"
#include "__franklist_operators.hpp"
#include "insert.hpp"


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

template <typename T>
void FrankList<T>::push_back(const_reference elem)
{
    if (tail == nullptr)
    {
        tail = new Node(elem);
        head = tail;
    }
    else
    {
        Node* tmp = new Node(elem);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}


template <typename T>
void FrankList<T>::pop_back()
{
    if (tail == nullptr)
        return;
    
    Node* tmp = tail;

    tail = tail->prev;

    if (tail != nullptr)
        tail->next = nullptr;

    if (head == tmp)
        head = tail;

    delete tmp;
}


template <typename T>
typename FrankList<T>::const_reference FrankList<T>::front() const
{
    return (this->head->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::front()
{
    return (const_cast<reference>(
    
        static_cast<const FrankList<T>*>(this)->front()
    ));
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::back() const
{
    return (this->tail->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::back()
{
    return (const_cast<reference>(
    
        static_cast<const FrankList<T>*>(this)->back()
    ));  
}


template <typename T>
typename FrankList<T>::const_reference FrankList<T>::min() const
{
    return (this->ahead->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::min()
{
    return (const_cast<reference>(
    
        static_cast<const FrankList<T>*>(this)->min()
    ));      
}


template <typename T>
typename FrankList<T>::const_reference FrankList<T>::max() const
{
    return (this->atail->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::max()
{
    return (const_cast<reference>(
    
        static_cast<const FrankList<T>*>(this)->max()
    ));    
}



#endif // __FRANKLIST_HPP_IMPL__
