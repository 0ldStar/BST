#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {
    BSTree<int> bsTree;
    bsTree.push(1, 1);
    bsTree.push(2, 2);
    bsTree.push(-1, -1);
    bsTree.push(-2, -2);
    cout << bsTree.getElementList();
    return 0;
}
