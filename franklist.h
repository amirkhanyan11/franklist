#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

#include <iostream>

namespace vhuk {

template <typename T>
class FrankList;

template <typename T>
std::ostream& operator<<(std::ostream& out, const FrankList<T>& rhv);

template <typename T>
class FrankList
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
private:
    struct Node
    {
        T val;
        Node* next;
        Node* prev;
        Node* asc;
        Node* desc;
        Node();
        Node(T val);
    };
private:
    class base_iterator // x
    {
        friend FrankList<value_type>;
    public:
        ~base_iterator();
        bool operator==(const base_iterator& rhv) const; //O(1) // x
        bool operator!=(const base_iterator& rhv) const; //O(1) // x
    protected:
        explicit base_iterator(Node* ptr); //O(1) // x
    protected:
        Node* ptr = nullptr;
    };
public:
    class const_iterator : public base_iterator // x
    {
        friend FrankList<value_type>;
    public:
        const_iterator(const base_iterator& rhv); //O(1) // x
        const_iterator(base_iterator&& rhv); //O(1) // x

        const const_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_iterator& operator++(); //O(1) // x
        const const_iterator operator++(value_type); //O(1) // x
        const const_iterator& operator--(); //O(1) // x
        const const_iterator operator--(value_type); //O(1) // x

    protected:
        explicit const_iterator(Node* ptr); //O(1) // x
    };

public:
    class iterator : public const_iterator
    {
        friend FrankList<value_type>;
    public:
        iterator(const base_iterator& rhv); //O(1) // x
        iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const iterator& operator=(const base_iterator& rhv); //O(1) // x
        const iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit iterator(Node* ptr); //O(1) // x
    };

public:
    class const_reverse_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_reverse_iterator(const base_iterator& rhv); //O(1) // x
        const_reverse_iterator(base_iterator&& rhv); //O(1) // x

        const const_reverse_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_reverse_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_reverse_iterator& operator++(); //O(1) // x
        const const_reverse_iterator operator++(value_type); //O(1) // x
        const const_reverse_iterator& operator--(); //O(1) // x
        const const_reverse_iterator operator--(value_type); //O(1) // x

    protected:
        explicit const_reverse_iterator(Node* ptr); //O(1) // x
    };
public:
    class reverse_iterator : public const_reverse_iterator
    {
        friend FrankList<value_type>;
    public:
        reverse_iterator(const base_iterator& rhv); //O(1) // x
        reverse_iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const reverse_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const reverse_iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit reverse_iterator(Node* ptr); //O(1) // x
    };
public:
    class const_asc_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_asc_iterator(const base_iterator& rhv); //O(1) // x
        const_asc_iterator(base_iterator&& rhv); //O(1) // x

        const const_asc_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_asc_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_asc_iterator& operator++(); //O(1) // x
        const const_asc_iterator operator++(value_type); //O(1) // x
        const const_asc_iterator& operator--(); //O(1) // x
        const const_asc_iterator operator--(value_type); //O(1) // x

    protected:
        explicit const_asc_iterator(Node* ptr); //O(1) // x
    };
public:
    class asc_iterator : public const_asc_iterator
    {
        friend FrankList<value_type>;
    public:
        asc_iterator(const base_iterator& rhv); //O(1) // x
        asc_iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const asc_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const asc_iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit asc_iterator(Node* ptr); //O(1)
    };
public:
    class const_desc_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_desc_iterator(const base_iterator& rhv); //O(1) // x
        const_desc_iterator(base_iterator&& rhv); //O(1) // x

        const const_desc_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_desc_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_desc_iterator& operator++(); //O(1) // x
        const const_desc_iterator operator++(value_type); //O(1) // x
        const const_desc_iterator& operator--(); //O(1) // x
        const const_desc_iterator operator--(value_type); //O(1) // x

    protected:
        explicit const_desc_iterator(Node* ptr); //O(1) // x
    };
public:
    class desc_iterator : public const_desc_iterator
    {
        friend FrankList<value_type>;
    public:
        desc_iterator(const base_iterator& rhv); //O(1) // x
        desc_iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const desc_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const desc_iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit desc_iterator(Node* ptr); //O(1) // x
    };
public:
    class const_multi_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_multi_iterator(const base_iterator& rhv); //O(1) // x
        const_multi_iterator(base_iterator&& rhv); //O(1) // x

        const const_multi_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_multi_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_multi_iterator& operator++(); //O(1) // x
        const const_multi_iterator operator++(value_type); //O(1) // x
        const const_multi_iterator& operator--(); //O(1) // x
        const const_multi_iterator operator--(value_type); //O(1) // x

        void chmod(); //O(1)

    protected:
        explicit const_multi_iterator(Node* ptr); //O(1) // x
        bool mode = true;
    };
public:
    class multi_iterator : public const_multi_iterator
    {
        friend FrankList<value_type>;
    public:
        multi_iterator(const base_iterator& rhv); //O(1) // x
        multi_iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const multi_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const multi_iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit multi_iterator(Node* ptr); //O(1) // x
    };
public:
    class const_multi_reverse_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_multi_reverse_iterator(const base_iterator& rhv); //O(1) // x
        const_multi_reverse_iterator(base_iterator&& rhv); //O(1) // x

        const const_multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const const_multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1) // x
        const_reference operator*() const; //O(1) // x
        const_pointer operator->() const; //O(1) // x

        const const_multi_reverse_iterator& operator++(); //O(1) // x
        const const_multi_reverse_iterator operator++(value_type); //O(1) // x
        const const_multi_reverse_iterator& operator--(); //O(1) // x
        const const_multi_reverse_iterator operator--(value_type); //O(1) // x


        void chmod(); //O(1)

    protected:
        explicit const_multi_reverse_iterator(Node* ptr); //O(1) // x
        bool mode = true;
    };
public:
    class multi_reverse_iterator : public const_multi_reverse_iterator // x
    {
        friend FrankList<value_type>;
    public:
        multi_reverse_iterator(const base_iterator& rhv); //O(1) // x
        multi_reverse_iterator(base_iterator&& rhv); //O(1) // x

        reference operator*(); //O(1) // x
        pointer operator->(); //O(1) // x

        const multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1) // x
        const multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1) // x


    protected:
        explicit multi_reverse_iterator(Node* ptr); //O(1) // x
    };

public:
    FrankList(); //O(1) // x
    FrankList(size_type size); //O(n) // x
    FrankList(size_type size, const_reference init); //O(n) // x
    FrankList(const FrankList<value_type>& rhv); //O(n) // x
    FrankList(FrankList<value_type>&& rhv); //O(1) // x
    FrankList(std::initializer_list<value_type> init); //O(n) // x
    template <typename input_iterator>
    FrankList(input_iterator f, input_iterator l); //O(n) // x
    ~FrankList();

public:
    void swap(FrankList<value_type>& rhv); //O(1) // x

    size_type size() const; //O(n) // x

    bool empty() const; //O(1) // x
    void resize(size_type s, const_reference init = value_type()); //O(n) // x
    void clear() noexcept; //O(n) // x

    void push_front(const_reference elem); //~O(1) // x
    void pop_front(); //O(1) // x
    void push_back(const_reference elem); //~O(1) // x
    void pop_back(); //O(1) // x

    const_reference front() const; //O(1) // x
    reference front(); //O(1) // x
    const_reference back() const; //O(1) // x
    reference back(); //O(1) // x
    const_reference min() const; //O(1) // x
    reference min(); //O(1) // x
    const_reference max() const; //O(1) // x
    reference max(); //O(1) // x

    const FrankList<value_type>& operator=(const FrankList<value_type>& rhv); //O(n) // x
    const FrankList<value_type>& operator=(FrankList<value_type>&& rhv); //O(n) // x
    const FrankList<value_type>& operator=(std::initializer_list<value_type> init); //O(n) // x

    bool operator==(const FrankList<value_type>& rhv) const; //O(n) // x
    bool operator!=(const FrankList<value_type>& rhv) const; //O(n) // x
    bool operator<(const FrankList<value_type>& rhv) const; //O(n) // x
    bool operator<=(const FrankList<value_type>& rhv) const; //O(n) // x
    bool operator>(const FrankList<value_type>& rhv) const; //O(n) // x
    bool operator>=(const FrankList<value_type>& rhv) const; //O(n) // x

public:
    const_iterator cbegin() const; //O(1) // x
    const_iterator cend() const; //O(1) // x
    const_reverse_iterator crbegin() const; //O(1) // x
    const_reverse_iterator crend() const; //O(1) // x
    const_asc_iterator cabegin() const; //O(1) // x
    const_asc_iterator caend() const; //O(1) // x
    const_desc_iterator cdbegin() const; //O(1) // x
    const_desc_iterator cdend() const; //O(1) // x
    const_multi_iterator cmbegin() const; //O(1) // x
    const_multi_iterator cmend() const; //O(1) // x
    const_multi_iterator cmabegin() const; //O(1) // x
    const_multi_iterator cmaend() const; //O(1) // x
    const_multi_reverse_iterator cmrbegin() const; //O(1) // x
    const_multi_reverse_iterator cmrend() const; //O(1) // x
    const_multi_reverse_iterator cmrdbegin() const; //O(1) // x
    const_multi_reverse_iterator cmrdend() const; //O(1) // x

    iterator begin(); //O(1) // x
    iterator end(); //O(1) // x
    reverse_iterator rbegin(); //O(1) // x
    reverse_iterator rend(); //O(1) // x
    asc_iterator abegin(); //O(1) // x
    asc_iterator aend(); //O(1) // x
    desc_iterator dbegin(); //O(1) // x
    desc_iterator dend(); //O(1) // x
    multi_iterator mbegin(); //O(1) // x
    multi_iterator mend(); //O(1) // x
    multi_iterator mabegin(); //O(1) // x
    multi_iterator maend(); //O(1) // x
    multi_reverse_iterator mrbegin(); //O(1) // x
    multi_reverse_iterator mrend(); //O(1) // x
    multi_reverse_iterator mrdbegin(); //O(1) // x
    multi_reverse_iterator mrdend(); //O(1) // x

public:
    // template <typename iter>
    // typename std::enable_if<std::is_base_of<const_iterator, iter>::value ||
    //                           std::is_base_of<const_asc_iterator, iter>::value ||
    //                           std::is_base_of<const_multi_iterator, iter>::value,
    //          iter>::type
    // insert(iter pos, const_reference val) { //O(1)
    //     return insert_def(pos, val);
    // }

    // template <typename iter>
    // typename std::enable_if<std::is_base_of<const_reverse_iterator, iter>::value ||
    //                           std::is_base_of<const_desc_iterator, iter>::value ||
    //                           std::is_base_of<const_multi_reverse_iterator, iter>::value,
    //          iter>::type
    // insert(iter pos, const_reference val) { //O(1)
    //     return insert_rev(pos, val);
    // }

    template <typename iter>
    typename std::enable_if<std::is_same<iterator, iter>::value ||
                              std::is_same<asc_iterator, iter>::value ||
                              std::is_same<multi_iterator, iter>::value,
             iter>::type
    insert(iter pos, const_reference val) { //O(1) // x
        return insert_def(pos, val);
    }

    template <typename iter>
    typename std::enable_if<std::is_same<reverse_iterator, iter>::value ||
                              std::is_same<desc_iterator, iter>::value ||
                              std::is_same<multi_reverse_iterator, iter>::value,
             iter>::type
    insert(iter pos, const_reference val) { //O(1) // x
        return insert_rev(pos, val);
    }

    template <typename iter>
    iter insert(iter pos, size_type size, const_reference val); //O(n) // x
    template <typename iter>
    iter insert(iter pos, std::initializer_list<value_type> init); //O(n) // x
    template <typename iter, typename input_iterator>
    iter insert(iter pos, input_iterator f, input_iterator l); //O(n) // x

    template <typename iter>
    iter erase(iter pos); //O(1) // x
    template <typename iter>
    iter erase(iter f, iter l); //O(n) // x

    size_type remove(const_reference val); //O(n) // x
    template <typename unary_predicate>
    size_type remove_if(unary_predicate func); //O(n) // x

    void reverse(); //O(n) // x
    void sort(bool reversed = false); //O(n) // x

    iterator find(const_reference elem); //O(n) // x
    iterator rfind(const_reference elem); //O(n) // x

    template <typename unary_predicate, typename iter>
    typename std::enable_if<std::is_same<iterator, iter>::value ||
                              std::is_same<asc_iterator, iter>::value ||
                              std::is_same<reverse_iterator, iter>::value ||
                              std::is_same<desc_iterator, iter>::value,
             void>::type
    traverse(unary_predicate func, iter f, iter l)
    {
        for (auto i = f; i != l; i++)
            func(*i);
    }

    template <typename iter>
    typename std::enable_if<std::is_same<iterator, iter>::value ||
                              std::is_same<asc_iterator, iter>::value ||
                              std::is_same<reverse_iterator, iter>::value ||
                              std::is_same<desc_iterator, iter>::value,
             void>::type
    print(iter f, iter l)
    {
        traverse([](const_reference i){std::cout << i << "  ";}, f, l);
    }


    template <typename unary_predicate>
    void traverse(unary_predicate func, bool sorted = false, bool reversed = false); //O(n) // x

    void print(bool sorted = false, bool reversed = false); //O(n) // x

protected:
    void put_in_sorted_order(Node* ptr); //O(n) // x
    void organize_left(Node* ptr); //O(1) // x
    void organize_right(Node* ptr); //O(1) // x
private:
    template <typename iter>
    iter insert_def(iter pos, const_reference val); //O(1) // x

    template <typename iter>
    iter insert_rev(iter pos, const_reference val); //O(1) // x


private:
    Node* head;
    Node* tail;
    Node* ahead;
    Node* atail;
};



}

#include "franklist.hpp"

#endif // _FRANKLIST_HPP__
