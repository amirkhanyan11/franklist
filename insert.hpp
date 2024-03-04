#ifndef __INSERT_HPP__
#define __INSERT_HPP__

#include "franklist.h"


template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, size_type size, const_reference val)
{

    if (pos == iter(this->begin()))
        while (size--)
            push_front(val);
    else if (pos == iter(this->end()))
        while (size--)
            push_back(val);
    else
    {
        FrankList<T> tmp = FrankList<T>(this->begin(), pos);

        while (size--)
            tmp.push_front(val);

        for (FrankList<T>::iterator i = pos; i != this->end(); ++i)
        {
            tmp.push_back(*i);
        }
        *this = std::move(tmp);
    }
    return (pos);
}


template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, std::initializer_list<T> init)
{
    FrankList<T> tmp = FrankList<T>(this->begin(), pos);

    for (auto i : init)
        tmp.push_back(i);

    for (FrankList<T>::iterator i = pos;
        i != this->end(); i++)
    {
        tmp.push_back(*i);
    }
    *this = std::move(tmp);

    return (pos);
}


template <typename T>
template <typename iter, typename input_iterator>
iter FrankList<T>::insert(iter pos, input_iterator f, input_iterator l)
{
    FrankList<T> tmp = FrankList<T>(this->begin(), pos);

    if (f != l)
    {

        size_type count = 0;

        for (input_iterator i = f; i != l; i++)
            count++;

        tmp.push_back(count);
    }

    for (FrankList<T>::iterator i = pos;
        i != this->end(); i++)
    {
        tmp.push_back(*i);
    }

    *this = std::move(tmp);

    return (pos);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_def(iter pos, const_reference val)
{
	Node* tmp = new Node(val);
    if (pos == iter(this->begin()))
        push_front(val);
    else if (pos == iter(this->end()))
        push_back(val);
	else
	{

		tmp->next = pos._ptr()->next;
		pos._ptr()->next->prev = tmp;

		pos._ptr()->next = tmp;
		tmp->prev = pos._ptr();

		put_in_sorted_order(tmp);
	}
	return (iter(tmp));
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev(iter pos, const_reference val)
{
	Node* tmp = new Node(val);
    if (pos == iter(this->begin()))
        push_front(val);
    else if (pos == iter(this->end()))
        push_back(val);
	else
	{

		tmp->prev = pos._ptr()->prev;
		pos._ptr()->prev->next = tmp;

		pos._ptr()->prev = tmp;
		tmp->next = pos._ptr();

		put_in_sorted_order(tmp);
	}
    return iter(tmp);
}


 // ORGANIZE METHODS
template <typename T>
void FrankList<T>::organize_left(Node* ptr)
{
	ptr->asc = ahead;
	ahead->desc = ptr;
	ahead = ptr;
}

template <typename T>
void FrankList<T>::organize_right(Node* ptr)
{
	ptr->desc = atail;
	atail->asc = ptr;
	atail = ptr;
}

template <typename T>
void FrankList<T>::put_in_sorted_order(Node* ptr)
{
	if (ptr->val < ahead->val)
		this->organize_left(ptr);
	else if (ptr->val > atail->val)
		this->organize_right(ptr);
	else
	{
		for (FrankList<T>::asc_iterator i = this->abegin(), j{i._ptr()->asc};
			i != this->aend(); i++, j++)
		{
			if (*i < ptr->val && *j >= ptr->val)
			{
				i._ptr()->asc = ptr;
				j._ptr()->desc = ptr;
				ptr->desc = i._ptr();
				ptr->asc = j._ptr();
				break;
			}
		}
	}
}


template <typename T>
typename FrankList<T>::iterator FrankList<T>::find(const_reference elem)
{
	for (FrankList<T>::iterator i = this->begin(); i != this->end(); i++)
	{
		if (*i == elem)
			return (i);
	}
	return iterator(nullptr);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem)
{
	for (FrankList<T>::reverse_iterator i = this->rbegin(); i != this->rend(); i++)
	{
		if (*i == elem)
			return (i);
	}
	return iterator(nullptr);
}


template <typename T>
void FrankList<T>::reverse()
{
	*this = FrankList<T>(const_reverse_iterator(this->crbegin()),
		const_reverse_iterator(this->crend()));
}


template <typename T>
void FrankList<T>::sort(bool reversed)
{
	if (reversed)
		*this = FrankList<T>(const_desc_iterator(this->cdbegin()), const_desc_iterator(this->cdend()));
	else
		*this = FrankList<T>(const_asc_iterator(this->cabegin()), this->caend());
}

#endif // __INSERT_HPP__
