//
// Created by loki on 30.10.22.
//

#ifndef ASD_2_BSTREESTRAIGHTITERATOR_H
#define ASD_2_BSTREESTRAIGHTITERATOR_H

#include "BSTreeIterator.h"

template<typename T>
class BSTreeStraightIterator : public BSTreeIterator<T> {
public:
    using value_type = T;
    using pointer = Node<T> *;
    using reference = BSTreeStraightIterator<T> &;

    BSTreeStraightIterator(pointer _root, unsigned _elementCount, int _ind) :
            BSTreeIterator<T>(_root, _elementCount, _ind) {};

    const reference &operator++() {
        BSTreeIterator<T>::ind++;
        if (BSTreeIterator<T>::ind == BSTreeIterator<T>::elementCount) BSTreeIterator<T>::ind = -1;
        return *this;
    }

    const reference &operator--(int) {
        BSTreeIterator<T>::ind--;
        return *this;
    }

    const reference operator++(int) {
        BSTreeIterator<T>::ind++;
        if (BSTreeIterator<T>::ind == BSTreeIterator<T>::elementCount) BSTreeIterator<T>::ind = -1;
        return *this;
    }
};


#endif //ASD_2_BSTREESTRAIGHTITERATOR_H
