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
    for (auto i : init)
	{
		pos = this->insert(pos, i);
	}
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
    if (pos.ptr == head)
	{
        push_front(val);
		return iter(head->next);
	}
    else if (pos.ptr == tail)
	{
        push_back(val);
		return iter(end());
	}

	tmp->next = pos.ptr;
	pos.ptr->prev->next = tmp;

	tmp->prev = pos.ptr->prev;
	pos.ptr->prev = tmp;

	put_in_sorted_order(tmp);

    return iter(tmp->next);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev(iter pos, const_reference val)
{
	Node* tmp = new Node(val);
    if (pos.ptr == head)
	{
        push_front(val);
		return iter(tail->prev);
	}
    else if (pos.ptr == tail)
	{
        push_back(val);
		return iter(head->prev);
	}
	tmp->prev = pos.ptr;
	pos.ptr->next->prev = tmp;

	tmp->next = pos.ptr->next;
	pos.ptr->next = tmp;

	put_in_sorted_order(tmp);

    return iter(tmp->prev);

}


template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter pos)
{
	if (pos == iter(nullptr))
		return pos;
	if (pos == iter(this->head))
		this->pop_front();
	else if (pos == iter(this->tail))
		this->pop_back();
	else
	{
		pos.ptr->prev->next = pos.ptr->next;
		pos.ptr->next->prev = pos.ptr->prev;

		this->organize_pop(pos.ptr);

		delete pos.ptr;

	}
	return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter f, iter l)
{
	for (iter i = f; i != l; )
	{
		iter j = i++;
		erase(j);
	}
	return f;
}


template <typename T>
typename FrankList<T>::size_type FrankList<T>::remove(const_reference val)
{
	size_type elements_removed = 0;

	for (FrankList<T>::iterator i = this->begin; i != this->end(); i++)
	{
		if (*i == val)
		{
			erase(i);
			elements_removed++;
		}
	}
	return (elements_removed);
}

template <typename T>
template <typename unary_predicate>
typename FrankList<T>::size_type FrankList<T>::remove_if(unary_predicate func)
{
	size_type elements_removed = 0;

	for (FrankList<T>::iterator i = this->begin(); i != this->end(); )
	{
		FrankList<T>::iterator j = i++;
		if (func(*j) == true)
		{
			erase(j);
			elements_removed++;
		}
	}

	return (elements_removed);
}



 // ORGANIZE METHODS
template <typename T>
void FrankList<T>::organize_left(Node* ptr)
{
	Node* to_swap = ptr->prev;


	to_swap->next = ptr->next;
	to_swap->prev->next = ptr;

	ptr->next = to_swap;

	ptr->prev = to_swap->prev;
	to_swap->prev = ptr;
	to_swap->next->prev = to_swap;
}

template <typename T>
void FrankList<T>::organize_right(Node* ptr)
{

}

template <typename T>
void FrankList<T>::put_in_sorted_order(Node* ptr)
{
	if (ahead == nullptr || atail == nullptr)
	{
		ahead = ptr;
		atail = ptr;
		return;
	}

	if (ptr->val < ahead->val)
	{
		ptr->asc = ahead;
		ahead->desc = ptr;
		ahead = ptr;
	}

	if (ptr->val > atail->val)
	{
		ptr->desc = atail;
		atail->asc = ptr;
		atail = ptr;
	}

	else
	{
		for (FrankList<T>::asc_iterator i = this->abegin();
			i != this->aend() && i.ptr->asc != nullptr; i++)
		{
			if (*i < ptr->val && i.ptr->asc->val >= ptr->val)
			{
				ptr->asc = i.ptr->asc;
				i.ptr->asc = ptr;

				ptr->asc->desc = ptr;
				ptr->desc = i.ptr;
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
		{
			if (i != iterator(this->begin()))
			{
				organize_left(i.ptr);
			}
			return (i);
		}
	}
	return iterator(nullptr);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem)
{
	for (FrankList<T>::reverse_iterator i = this->rbegin(); i != this->rend(); i++)
	{
		if (*i == elem)
		{
			if (i != iterator(this->rbegin()))
			{
				organize_right(i.ptr);
			}
			return (i);
		}
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
	if (!reversed)
	{
		head = ahead;
		tail = head;

		for (auto i = abegin(); i != aend(); i++)
		{
			tail->next = i.ptr->asc;
			tail = tail->next;
		}
	}
	else
	{
		head = atail;
		tail = head;

		for (auto i = dbegin(); i != dend(); i++)
		{
			tail->next = i.ptr->desc;
			tail = tail->next;
		}
	}
}

#endif // __INSERT_HPP__
