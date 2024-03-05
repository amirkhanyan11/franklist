#include "node.hpp"
#include "iterators.hpp"


// CONSTANTS

// const_iterator
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
	return const_iterator(head);
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const
{
	return (tail == nullptr) ? const_iterator(nullptr) : (const_iterator(tail->next));
}

// const_reverse_iterator
template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
	return const_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
	return (head == nullptr) ? const_reverse_iterator(nullptr) : (const_reverse_iterator(head->prev));
}

// const_asc_iterator
template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
	return const_asc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
	return (atail == nullptr) ? const_asc_iterator(nullptr) : (const_asc_iterator(atail->asc));
}

// const_desc_iterator
template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
	return const_desc_iterator(atail);
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{
	return (ahead == nullptr) ? const_desc_iterator(nullptr) : (const_desc_iterator(ahead->desc));
}

// const_multi_iterator
template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
{
	return const_multi_iterator(head);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
{
	return (tail == nullptr) ? const_multi_iterator(nullptr) : (const_multi_iterator(tail->next));
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
{
	auto iter = const_multi_iterator(ahead);
	iter.chmod();
	return iter;
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
{
	auto iter = const_multi_iterator(atail->asc);
	iter.chmod();
	return (atail == nullptr) ? const_multi_iterator(nullptr) : (iter);
}

// const_multi_reverse_iterator
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
{
	return const_multi_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
{
	return (head == nullptr) ? const_multi_reverse_iterator(nullptr) : const_multi_reverse_iterator(head->prev);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
{
	auto iter = const_multi_reverse_iterator(atail);
	iter.chmod();
	return iter;
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
{
	auto iter = const_multi_reverse_iterator(ahead->desc);
	iter.chmod();
	return (ahead == nullptr) ? const_multi_reverse_iterator(nullptr) : iter;
}


// NON-CONSTANTS

// iterator
template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin()
{
	return iterator(this->cbegin());
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end()
{
	return iterator(this->cend());
}

// reverse_iterator
template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
{
	return reverse_iterator(this->crbegin());
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend()
{
	return reverse_iterator(this->crend());
}

// asc_iterator
template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin()
{
	return (asc_iterator(this->cabegin()));
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend()
{
	return asc_iterator(this->caend());
}

// desc_iterator
template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
{
	return desc_iterator(this->cdbegin());
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend()
{
	return desc_iterator(this->cdend());
}

// multi_iterator
template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mbegin()
{
	return multi_iterator(this->cmbegin());
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mend()
{
	return multi_iterator(this->cmend());
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mabegin()
{
	return multi_iterator(this->cmabegin());
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::maend()
{
	return multi_iterator(this->cmaend());
}

// multi_reverse_iterator
template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
{
	return multi_reverse_iterator(this->cmrbegin());
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
{
	return multi_reverse_iterator(this->cmrend());
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
{
	return multi_reverse_iterator(this->cmrdbegin());
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
{
	return multi_reverse_iterator(this->cmrdend());
}
