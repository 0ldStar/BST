//
// Created by loki on 29.10.22.
//

#ifndef ASD_2_NODE_H
#define ASD_2_NODE_H

template<typename T>
struct Node {
    Node(T _data, int _key, Node *_parent) : data(_data), key(_key), right(nullptr), left(nullptr), parent(_parent) {};

    Node(T _data, int _key, Node *_parent, Node *_left, Node *_right) : data(_data), key(_key), right(_right),
                                                                        left(_left), parent(_parent) {};
    T data;
    int key;
    Node *right;
    Node *left;
    Node *parent;
};

#endif //ASD_2_NODE_H
