#include "node.hpp"
#include "iterators.hpp"


// CONSTANTS

// const_iterator
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
	return (const_iterator(head));
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const
{
	return (const_iterator(nullptr));
}

// const_reverse_iterator
template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
	return (const_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
	return (const_reverse_iterator(head->prev));
}

// const_asc_iterator
template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
	return (const_asc_iterator(ahead));
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
	return (const_asc_iterator(atail->asc));
}

// const_desc_iterator
template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
	return (const_desc_iterator(atail));
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{
	return (const_desc_iterator(ahead->desc));
}

// const_multi_iterator
template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
{
	return (const_multi_iterator(head));
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
{
	return (const_multi_iterator(tail->next));
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
{
	return (const_multi_iterator(ahead));
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
{
	return (const_multi_iterator(atail->asc));
}

// const_multi_reverse_iterator
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
{
	return (const_multi_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
{
	return (const_multi_reverse_iterator(head->prev));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
{
	return (const_multi_reverse_iterator(atail));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
{
	return (const_multi_reverse_iterator(ahead->desc));
}


// NON-CONSTANTS

// iterator
template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin()
{
	return (iterator(head));
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end()
{
	return (nullptr);
}

// reverse_iterator
template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
{
	return (reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend()
{
	return (reverse_iterator(head->prev));
}

// asc_iterator
template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin()
{
	return (asc_iterator(ahead));
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend()
{
	return (asc_iterator(atail->asc));
}

// desc_iterator
template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
{
	return (desc_iterator(atail));
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend()
{
	return (desc_iterator(ahead->desc));
}

// multi_iterator
template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mbegin()
{
	return (multi_iterator(head));
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mend()
{
	return (multi_iterator(tail->next));
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mabegin()
{
	return (multi_iterator(ahead));
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::maend()
{
	return (multi_iterator(atail->asc));
}

// multi_reverse_iterator
template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
{
	return (multi_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
{
	return (multi_reverse_iterator(head->prev));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
{
	return (multi_reverse_iterator(atail));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
{
	return (multi_reverse_iterator(ahead->desc));
}
