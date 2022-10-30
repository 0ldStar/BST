//
// Created by loki on 29.10.22.
//

#ifndef ASD_2_BSTREE_H
#define ASD_2_BSTREE_H

#include <iostream>
#include <string>
#include <stack>
#include "Node.h"

template<typename T>
class BSTree {
public:
    BSTree();

    BSTree(BSTree &other);

    ~BSTree();

    unsigned getLength();

    void clear();

    bool isEmpty();

    T &operator[](unsigned ind);

    bool push(int key, T data);

    bool pop(int key);

    std::string getElementList();

    bool merge(BSTree<T> &other);

    void begin();

    void end();

    void rbegin();

    void rend();

    void printStructure();

    unsigned getLaboriousness;
private:
    void moveOnTree(void (BSTree<T>::*func)(Node<T> *));

    void putElementInStr(T data);

    std::string elementList;
    Node<T> *root;
    unsigned elementCount;

};

#endif //ASD_2_BSTREE_H
