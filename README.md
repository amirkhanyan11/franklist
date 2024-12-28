
# FrankList 📜: A Fusion of Elegance and Creativity in C++

FrankList is a **highly customizable, creatively designed** data structure inspired by the need to think beyond conventional linked lists. This library is not just about functionality—it's about **exploring novel concepts**, redefining iteration paradigms, and **writing code that’s genuinely fun to create and use**.  

## Key Features 🚀
1. **Multidirectional Traversal**:  
   Navigate through nodes in **ascending, descending**, or **multimode** order with specialized iterators.
2. **Enhanced Iterators**:  
   A rich hierarchy of iterators—forward, reverse, ascending, descending, and even multi-iterators for dynamic behaviors.  
3. **Sorted Organization**:  
   Seamlessly keeps elements in sorted order when needed with an optional `sorted` flag.  
4. **Algorithm-Friendly**:  
   Offers utility functions for `sort`, `reverse`, `find`, and more, making it easy to integrate into algorithm-heavy projects.
5. **Creative Insertions and Erasures**:  
   Highly flexible insert and erase functionalities to modify the list in unconventional ways.  
6. **Traverse with Style**:  
   Pass custom unary predicates to the `traverse` method for creative manipulation of elements.

---

## Why FrankList? 🤔

FrankList stands out because it’s not just a data structure—it’s a **playground for innovative design patterns**. Whether you're traversing via `asc_iterator`, experimenting with `multi_reverse_iterator`, or marveling at the implicit organization of the nodes, **it’s an exploration into what linked lists can truly become.**

This is not a library you use—it’s a library you **enjoy**.

---

## Installation 💾

Simply include `franklist.hpp` in your project directory, and you’re ready to go!  

```cpp
#include "franklist.hpp"
```

Make sure your compiler supports C++11 or later.

---

## Getting Started 🚦

Here's a taste of what FrankList can do:

```cpp
#include "franklist.hpp"

int main() {
    vhuk::FrankList<int> fl{10, 20, 30};

    fl.push_front(5);
    fl.push_back(40);

    std::cout << "Forward traversal: ";
    fl.print(); // Prints the list in standard order.

    std::cout << "Ascending order: ";
    fl.print(true); // Prints the list in ascending order.
}
```

---

## Iterators: The Real Stars ✨

FrankList boasts a **hierarchical iterator system** that gives you full control:

- **`asc_iterator`**: Traverse in ascending order.  
- **`desc_iterator`**: Traverse in descending order.  
- **`multi_iterator`**: Toggle between behaviors dynamically.  
- **`reverse_iterator`**: Standard reverse traversal.  

Each iterator inherits from the base iterator, ensuring **polymorphic flexibility**.

---

## Behind the Scenes 🤯

FrankList uses a **unique node structure** with four pointers:  
- `next` and `prev` for conventional navigation.  
- `asc` and `desc` for sorted traversal.  

These additions make FrankList a **powerful yet intuitive** data structure that balances performance and creative design.

---

## Contribution ❤️

If FrankList sparks your curiosity, feel free to fork the repo and contribute your ideas. The only rule? Have fun writing code!

---

## License 📜

This project is open-source and available under the MIT License.  
