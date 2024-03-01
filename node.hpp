
#include "franklist.h"

using namespace vhuk;

template <typename T>
FrankList<T>::Node::Node()
    
    : val{},
    next{nullptr},
    prev{nullptr},
    asc{nullptr},
    desc{nullptr} {}

template <typename T>
FrankList<T>::Node::Node(T val)
    
    : val{val},
    next{nullptr},
    prev{nullptr},
    asc{nullptr},
    desc{nullptr} {}   