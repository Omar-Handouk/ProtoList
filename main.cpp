#include <iostream>
#include <stdexcept>
#include "ProtoList.h"

#define PRINTER list1.display()

using namespace std;

int main(int argC, char *argV[]) {

    ProtoList list1;
    ProtoList list2(1);

    int arr[5] = {1, 2, 3, 4, 5};

    ProtoList list3(arr, 5);

    PRINTER; //Should not print anything

    list1.insertFirst(1);
    PRINTER;
    list1.insertLast(2);
    PRINTER;
    list1.insertPos(3, 1);
    PRINTER;

    list1.insertFirst(4);
    PRINTER;
    list1.insertFirst(5);
    PRINTER;
    list1.insertFirst(6);
    PRINTER;

    list1.deleteFirst();
    PRINTER;
    list1.deleteLast();
    PRINTER;
    list1.deletePos(1);
    PRINTER;

    list1.update(10, 0);
    PRINTER;

    ProtoList::Node *node = list1.get(1);
    int n = node->getData();
    cout << n << "\n";

    cout << list1.getSize();


    return 0;
}