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

    : head {new Node()},
    tail{head},
    ahead{nullptr},
    atail{nullptr}
{

    for (int i = 1; i < size; i++)
    {
        tail->next = new Node();
        tail = tail->next;
    }
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

    for (auto i = head; i != nullptr; i = i->next)
        lstsize++;


    return lstsize;
}
