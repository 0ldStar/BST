//
// Created by loki on 29.10.22.
//

#ifndef ASD_2_BSTREE_H
#define ASD_2_BSTREE_H

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include "Node.h"
#include "BSTreeStraightIterator.h"
#include "BSTreeBackIterator.h"

template<typename T>
class BSTree {
public:
    BSTree();

    BSTree(BSTree<T> &other);

    ~BSTree();

    unsigned getLength();

    void clear();

    bool isEmpty();

    T &operator[](unsigned key);

    bool push(int key, T data);

    bool pop(int key);

    std::string getKeysList();

    bool merge(BSTree<T> &other);

    BSTreeStraightIterator<T> begin();

    BSTreeStraightIterator<T> end();

    BSTreeBackIterator<T> rbegin();

    BSTreeBackIterator<T> rend();

    void printStructure();

    unsigned getLaboriousness();

private:
    void putElementInStr(T data);

    void popSwapNodes(Node<T> *target);

    T getDefaultValue();

    unsigned laboriousness;
    std::string elementList;
    Node<T> *root;
    unsigned elementCount;
    unsigned maxLayer;
    T defaultValue;
};

#endif //ASD_2_BSTREE_H
