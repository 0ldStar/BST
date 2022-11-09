#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {
    BSTree<int> bsTree;
    list<int> Mlist = *new list<int>;
    bsTree.push(60, 60);
    bsTree.push(70, 70);
    bsTree.push(20, 20);
    bsTree.push(10, 10);
    bsTree.push(5, 5);
    bsTree.push(17, 17);
    bsTree.push(40, 40);
    bsTree.push(30, 30);
    bsTree.push(50, 50);
    bsTree.push(65, 65);
    bsTree.push(75, 75);
    bsTree.push(80, 80);

    cout << bsTree.getKeysList() << endl;
    bsTree.printStructure();
    cout << endl << endl;

    BSTree<int> bsTreeOther(bsTree);
    cout << bsTreeOther.getKeysList() << endl;

    BSTree<int> bsTreeOther2;
    bsTreeOther2.push(1, 1);
    bsTreeOther2.push(80, 80);
    bsTree.merge(bsTreeOther2);
    cout << bsTree.getKeysList() << endl;


    cout << "StraightIterator" << endl;
    for (auto it = bsTree.begin(); it != bsTree.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "BackIterator" << endl;
    for (auto it = bsTree.rbegin(); it != bsTree.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    bsTree.clear();
//    bsTree.pop(60);
//    bsTree.pop(70);
//    bsTree.pop(20);
//    bsTree.pop(10);
//    bsTree.pop(5);
//    bsTree.pop(17);
//    bsTree.pop(40);
//    bsTree.pop(30);
//    bsTree.pop(50);
//    bsTree.pop(65);
//    bsTree.pop(75);
    cout << bsTree.getKeysList() << endl;
    return 0;
}
