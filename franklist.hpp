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
	head = nullptr;
	tail = nullptr;
	ahead = nullptr;
	atail = nullptr;
}

template <typename T>
void FrankList<T>::resize(size_type s, const_reference init)
{
    for (size_type i = 0; i < s; i++)
    {
        this->push_back(init);
    }
}



template <typename T>
void FrankList<T>::push_front(const_reference elem)
{
    Node* tmp = new Node(elem);
    if (this->empty())
    {
        head = tmp;
        tail = head;
    }
    else
    {
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
	put_in_sorted_order(tmp);
}

template <typename T>
void FrankList<T>::push_back(const_reference elem)
{
	Node* tmp = new Node(elem);

    if (this->empty())
    {
        tail = tmp;
        head = tail;
    }
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
	put_in_sorted_order(tmp);
}

template <typename T>
void FrankList<T>::pop_front()
{
    if (this->empty())
        return;

    Node* tmp = head;

    head = head->next;

    this->organize_pop(tmp);

    if (head != nullptr)
        head->prev = nullptr;

    if (tail == tmp)
        tail = head;

    delete tmp;
}

template <typename T>
void FrankList<T>::pop_back()
{
    if (this->empty())
        return;

    Node* tmp = tail;

    this->organize_pop(tmp);

    tail = tail->prev;

    if (tail != nullptr)
        tail->next = nullptr;

    if (head == tmp)
        head = tail;

    delete tmp;
}


template <typename T>
void FrankList<T>::organize_pop(Node* ptr)
{
	if (ptr != this->ahead)
		ptr->desc->asc = ptr->asc;
	else
		this->ahead = ptr->asc;
	if (ptr != this->atail)
		ptr->asc->desc = ptr->desc;
	else
		this->tail = ptr->desc;
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

template <typename T>
template <typename unary_predicate>
void FrankList<T>::traverse(unary_predicate func, bool sorted, bool reversed)
{
    if (sorted && reversed)
        for (desc_iterator i = this->dbegin(); i != this->dend(); i++)
            func(*i);
    else if (sorted && !reversed)
        for (asc_iterator i = this->abegin(); i != this->aend(); i++)
            func(*i);
    else if (!sorted && reversed)
        for (reverse_iterator i = this->rbegin(); i != this->rend(); i++)
            func(*i);
    else
        for (iterator i = this->begin(); i != this->end(); i++)
            func(*i);
}

template <typename T>
void FrankList<T>::print(bool sorted, bool reversed)
{
    traverse([](const_reference i){std::cout << i << "  ";}, sorted, reversed);
}


#endif // __FRANKLIST_HPP_IMPL__
