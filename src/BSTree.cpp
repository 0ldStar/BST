//
// Created by loki on 29.10.22.
//

#include "BSTree.h"

using namespace std;

template<typename T>
BSTree<T>::BSTree() {
    root = nullptr;
    elementCount = 0;
}

template<typename T>
BSTree<T>::~BSTree() {

}

#include <list>

template<typename T>
bool BSTree<T>::push(int key, T data) {
    auto nodeList = new list<Node<T> *>();
    Node<T> *top = root;
    if (!top) {
        root = new Node<T>(data, key, nullptr);
        return true;
    }
    while (top != nullptr || !nodeList->empty()) {
        if (key < top->key) {
            if (!top->left) {
                top->left = new Node<T>(data, key, top);
                return true;
            } else {
                nodeList->push_front(top->left);
            }
        } else if (key > top->key) {
            if (!top->right) {
                top->right = new Node<T>(data, key, top);
                return true;
            } else {
                nodeList->push_front(top->right);
            }
        } else {
            auto *tmp = new Node<T>(data, top->key, top->parent, top->left, top->right);
            if (top->left) {
                top->left->parent = tmp;
            }
            if (top->right) {
                top->right->parent = tmp;
            }
            if (top->parent) {
                if (top == top->parent->left) {
                    top->parent->left = tmp;
                } else {
                    top->parent->right = tmp;
                }
            }
            delete top;
            top = tmp; // todo need to check
            return true;
        }
        top = nodeList->back();
        nodeList->pop_back();
    }
}

template<typename T>
std::string BSTree<T>::getElementList() {
    elementList.clear();
    auto nodeList = new list<Node<T> *>();
    Node<T> *top = root;
    while (top != nullptr || !nodeList->empty()) {
        if (!nodeList->empty()) {
            top = nodeList->front();
            nodeList->pop_front();
            putElementInStr(top->key);
            if (top->right != nullptr) top = top->right;
            else top = nullptr;
        }
        while (top != nullptr) {
            nodeList->push_front(top);
            top = top->left;
        }
    }
    return elementList;
}


template<typename T>
void BSTree<T>::putElementInStr(T data) {
    elementList.append(to_string(data));
    elementList.append(" ");
}

template
class BSTree<int>;

template
class BSTree<char>;

template
class BSTree<float>;