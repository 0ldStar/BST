#include <iostream>
#include "menu.h"

using namespace std;
BSTree<int> bsTree;
BSTree<int> other;

int main() {
    system("clear");
    int command = -1;
    while (command != 14) {
        printf("\tThis is interactive menu for List in Array structure.\n"
               "What you want to do?\n"
               "1) Fill the bsTree.\n"
               "2) Get bsTree length.\n"
               "3) Clear the bsTree.\n"
               "4) Check is the bsTree empty.\n"
               "5) Get value from the bsTree by key.\n"
               "6) Change value from the bsTree by key.\n"
               "7) Delete value from the bsTree.\n"
               "8) Print values.\n"
               "9) Print tree structure.\n"
               "10) Get laboriousness.\n"
               "11) Straight iterator menu.\n"
               "12) Back iterator menu.\n"
               "13) Merge tree.\n"
               "14) Exit.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                printFillMenu();
                break;
            case 2:
                cout << "List len = " << bsTree.getLength() << endl;
                break;
            case 3:
                if (!bsTree.isEmpty())
                    bsTree.clear();
                else
                    cout << "List is empty." << endl;
                break;
            case 4:
                cout << "Is bsTree empty? " << (bsTree.isEmpty() ? "True" : "False") << endl;
                break;
            case 5:
                if (!bsTree.isEmpty())
                    getElementMenu();
                else
                    cout << "List is empty." << endl;
                break;
            case 6:
                if (!bsTree.isEmpty())
                    fillValue();
                else
                    cout << "List is empty." << endl;
                break;
            case 7:
                if (!bsTree.isEmpty())
                    deleteValue();
                else
                    cout << "List is empty." << endl;
                break;
            case 8:
                if (!bsTree.isEmpty())
                    cout << bsTree.getKeysList() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            case 9:
                if (!bsTree.isEmpty())
                    bsTree.printStructure();
                else
                    cout << "List is empty." << endl;
                break;
            case 10:
                if (!bsTree.isEmpty())
                    cout << "Laboriousness: " << bsTree.getLaboriousness() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            case 11:
                if (!bsTree.isEmpty())
                    straightIterMenu();
                else
                    cout << "List is empty." << endl;
                break;
            case 12:
                if (!bsTree.isEmpty())
                    backIterMenu();
                else
                    cout << "List is empty." << endl;
                break;
            case 13:
                other.clear();
                for (int i = 25; i < 30; ++i) {
                    other.push(i, i);
                }
                bsTree.merge(other);
                break;
            default:
                break;
        }
    }
    return 0;
}
