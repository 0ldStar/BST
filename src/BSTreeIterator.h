//
// Created by loki on 30.10.22.
//

#ifndef ASD_2_BSTREEITERATOR_H
#define ASD_2_BSTREEITERATOR_H

#include "Node.h"

template<typename T>
class BSTreeIterator {
//        using iterator_category = std::bidirectional_iterator_tag;
//        using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;
    using pointer = Node <T> *;  // or also value_type*
    using reference = Node <T> &;  // or also value_type&

    BSTreeIterator(pointer _ptr, int _ind) {
        ptr = _ptr;
        ind = _ind;
    }

    T &operator*() const { return ptr[ind].data; }

    pointer operator->() { return &ptr[ind]; }

    const BSTreeIterator &operator++() {
        ind = ptr[ind].nextInd;
        return *this;
    }

    const BSTreeIterator &operator--(int) {
        ind = ptr[ind].prevInd;
        return *this;
    }

    const BSTreeIterator operator++(int) {
        ind = ptr[ind].nextInd;
        return *this;
    }

    int getInd() { return ind; }

    friend bool operator==(const BSTreeIterator &a, const BSTreeIterator &b) { return a.ind == b.ind; };

    friend bool operator!=(const BSTreeIterator &a, const BSTreeIterator &b) { return a.ind != b.ind; };
private:
    int ind;
    pointer ptr;
};


#endif //ASD_2_BSTREEITERATOR_H
