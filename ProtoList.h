#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef SAPPHIRE_LINKEDLIST_H
#define SAPPHIRE_LINKEDLIST_H

class ProtoList {
public:
    //Node Deceleration
    struct Node {
    public:
        Node();

        Node(int data);

        int getData() const;

        void setData(int data);

        Node *getNext() const;

        void setNext(Node *next);

    private:
        int data;
        Node *next;
    };

    //Constructors
    ProtoList();

    ProtoList(int data);

    ProtoList(int *data, int arrSize);

    //Functions

    void insertFirst(int data);

    void insertLast(int data);

    void insertPos(int data, int pos);

    //If a node doesn't exist a nullptr or a false value is returned

    void deleteFirst();

    void deleteLast();

    void deletePos(int pos);

    bool update(int data, int pos);

    Node *get(int pos);

    int getSize() const;

    void display() const;

private:
    Node *HEAD = nullptr, *TAIL = nullptr;
    int size = 0;

    ProtoList::Node *createNode(int data);

    void parseArray(int *arr, int arrSize);

    class NonExistingElement : public runtime_error {
    public:
        explicit NonExistingElement(const string &__arg);

        const char *what() const noexcept override;

    };

};

#endif //SAPPHIRE_LINKEDLIST_H
