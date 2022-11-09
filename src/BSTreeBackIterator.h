//
// Created by loki on 06.11.22.
//

#ifndef ASD_2_BSTREEBACKITERATOR_H
#define ASD_2_BSTREEBACKITERATOR_H

#include "BSTreeIterator.h"

template<typename T>
class BSTreeBackIterator : public BSTreeIterator<T> {
public:
    using value_type = T;
    using pointer = Node<T> *;
    using reference = BSTreeBackIterator<T> &;

    BSTreeBackIterator(pointer _root, unsigned _elementCount, int _ind) :
            BSTreeIterator<T>(_root, _elementCount, _ind) {};

    const reference &operator++() {
        BSTreeIterator<T>::ind--;
        return *this;
    }

    const reference &operator--(int) {
        BSTreeIterator<T>::ind++;
        if (BSTreeIterator<T>::ind == BSTreeIterator<T>::elementCount) BSTreeIterator<T>::ind = -1;
        return *this;
    }

    const reference operator++(int) {
        BSTreeIterator<T>::ind--;
        return *this;
    }
};


#endif //ASD_2_BSTREEBACKITERATOR_H
