//
// Created by loki on 22.10.22.
//
#include "menu.h"

#define START_LENGTH 10
extern BSTree<int> bsTree;

void printFillMenu() {
    int command = -1;
    while (command != 4) {
        printf("What you want to do?\n"
               "1) Fill random value.\n"
               "2) Fill stepped value.\n"
               "3) Add new value to the bsTree.\n"
               "4) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                fillRandom();
                return;
            case 2:
                fillStepped();
                return;
            case 3:
                fillValue();
                return;
            default:
                break;
        }
    }
}

void getElementMenu() {
    int key = -1;
    std::cout << "Enter key:";
    std::cin >> key;
    int value = bsTree[key];
    if (bsTree.getLaboriousness() != -1)
        std::cout << std::endl << "Value: " << value << std::endl;
    else
        std::cout << std::endl << "Bad key!" << std::endl;

}

void fillRandom() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < START_LENGTH; ++i) {
        bsTree.push((START_LENGTH - i) / 2 - 1, 1 + (int) (std::rand() / ((RAND_MAX + 1u) / 20)));
    }
}

void fillStepped() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < START_LENGTH; ++i) {
        bsTree.push((START_LENGTH / 2 - i) - 1, (START_LENGTH / 2 - i) - 1);
    }
}

void fillValue() {
    int key, num;
    std::cout << "Enter key:";
    std::cin >> key;
    std::cout << "Enter value:";
    std::cin >> num;
    std::cout << std::endl;
    bsTree.push(key, num);
}

void deleteValue() {
    int key;
    std::cout << "Enter key:";
    std::cin >> key;
    std::cout << std::endl;
    bsTree.pop(key);
}

void straightIterMenu() {
    int command = -1;
    BSTreeStraightIterator<int> iter = BSTreeStraightIterator<int>(nullptr, 0, -2);

    while (command != 7) {
        printf("What you want to do?\n"
               "1) Set iterator to the start of the bsTree.\n"
               "2) Set iterator to step by value.\n"
               "3) Increment iterator.\n"
               "4) Decrement iterator.\n"
               "5) Get element from iterator.\n"
               "6) Print keys.\n"
               "7) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                iter = bsTree.begin();
                break;
            case 2:
                unsigned step;
                std::cout << "Enter step: ";
                std::cin >> step;
                if (step > 0 && step < bsTree.getLength()) {
                    iter = bsTree.begin();
                    for (unsigned i = 0; i < step; ++i) iter++;
                } else {
                    std::cout << "[Error] Invalid step" << std::endl;
                }
                break;
            case 3:
                if (iter.getInd() >= 0 && iter.getInd() != bsTree.getLength() - 1) {
                    iter++;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 4:
                if (iter.getInd() > 0) {
                    iter--;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 5:
                if (iter.getInd() != -2) {
                    std::cout << "Value: " << *iter << std::endl;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 6:
                if (!bsTree.isEmpty()) {
                    for (auto it = bsTree.begin(); it != bsTree.end(); it++) {
                        std::cout << it.getKey() << " ";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "List is empty." << std::endl;
                }
                break;
            default:
                break;
        }
    }
}

void backIterMenu() {
    int command = -1;
    BSTreeBackIterator<int> iter = BSTreeBackIterator<int>(nullptr, 0, -2);

    while (command != 7) {
        printf("What you want to do?\n"
               "1) Set iterator to the end of the bsTree.\n"
               "2) Set iterator to step by value.\n"
               "3) Increment iterator.\n"
               "4) Decrement iterator.\n"
               "5) Get element from iterator.\n"
               "6) Print keys.\n"
               "7) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                iter = bsTree.rbegin();
                break;
            case 2:
                unsigned step;
                std::cout << "Enter step: ";
                std::cin >> step;
                if (step > 0 && step < bsTree.getLength()) {
                    iter = bsTree.rbegin();
                    for (unsigned i = 0; i < step; ++i) iter++;
                } else {
                    std::cout << "[Error] Invalid step" << std::endl;
                }
                break;
            case 3:
                if (iter.getInd() > 0) {
                    iter++;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 4:
                if (iter.getInd() >= 0 && iter.getInd() != bsTree.getLength() - 1) {
                    iter--;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 5:
                if (iter.getInd() >= 0) {
                    std::cout << "Value: " << *iter << std::endl;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 6:
                if (!bsTree.isEmpty())
                    std::cout << bsTree.getKeysList() << std::endl;
                else
                    std::cout << "List is empty." << std::endl;
                break;
            default:
                break;
        }
    }
}