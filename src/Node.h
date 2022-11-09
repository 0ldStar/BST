//
// Created by loki on 29.10.22.
//

#ifndef ASD_2_NODE_H
#define ASD_2_NODE_H

template<typename T>
struct Node {
    Node(T _data, int _key, Node *_parent, unsigned _layer) : data(_data), key(_key), right(nullptr), left(nullptr),
                                                              parent(_parent), layer(_layer) {};

    Node(T _data, int _key, Node *_parent, Node *_left, Node *_right, unsigned _layer) : data(_data), key(_key),
                                                                                         right(_right), left(_left),
                                                                                         parent(_parent), layer(_layer) {};
    Node(int _data, int _key):data(_data), key(_key), right(nullptr), left(nullptr),
                    parent(nullptr), layer(0){};
    Node(char _data, int _key):data(_data), key(_key), right(nullptr), left(nullptr),
                    parent(nullptr), layer(0){};
    Node(float _data, int _key):data(_data), key(_key), right(nullptr), left(nullptr),
                    parent(nullptr), layer(0){};
    T data;
    int key;
    unsigned layer;
    Node *right;
    Node *left;
    Node *parent;
};

#endif //ASD_2_NODE_H
