#ifndef __FRANKLIST_OPERATORS_HPP__
#define __FRANKLIST_OPERATORS_HPP__

#include "franklist.hpp"

// ASSIGNMENT OPERATORS
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

// BOOLEAN OPERATORS
template <typename T>
bool FrankList<T>::operator==(const FrankList<T>& rhv) const
{

    if (!this->empty() && !rhv.empty())
    {

        FrankList<T>::const_iterator i = this->cbegin();
        FrankList<T>::const_iterator j = rhv.cbegin();

        while (i != this->cend() && j != rhv.cend())
        {
            if (*i != *j)
                return false;
            ++i;
            ++j;
        }
        return (this->back() == rhv.back());
    }
    return (this->empty() && rhv.empty());
}


template <typename T>
bool FrankList<T>::operator!=(const FrankList<T>& rhv) const
{
    return !(*this == rhv);
}


template <typename T>
bool FrankList<T>::operator<(const FrankList<T>& rhv) const
{

    if (!this->empty() && !rhv.empty())
    {
        FrankList<T>::const_iterator i = this->cbegin();
        FrankList<T>::const_iterator j = rhv.cbegin();

        while (i != this->cend() && j != rhv.cend())
        {
            if (*i != *j)
                return (*i < *j);
            ++i;
            ++j;
        }
    }
    return (this->empty() && !rhv.empty());
}


template <typename T>
bool FrankList<T>::operator<=(const FrankList<T>& rhv) const
{
    return ((*this < rhv) || (*this == rhv));
}



template <typename T>
bool FrankList<T>::operator>(const FrankList<T>& rhv) const
{
    return !(*this <= rhv);
}

template <typename T>
bool FrankList<T>::operator>=(const FrankList<T>& rhv) const
{
    return !(*this < rhv);
}


#endif // __FRANKLIST_OPERATORS_HPP__
