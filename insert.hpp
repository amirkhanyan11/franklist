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

        for (FrankList<T>::const_iterator i = pos;
            i != this->cend(); ++i)
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

    for (FrankList<T>::const_iterator i = pos;
        i != this->cend(); i++)
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
    
    for (FrankList<T>::const_iterator i = pos;
        i != this->cend(); i++)
    {
        tmp.push_back(*i);
    }

    *this = std::move(tmp);

    return (pos);
}



#endif // __INSERT_HPP__