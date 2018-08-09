#include <iostream>
#include <stdexcept>
#include "ProtoList.h"

using namespace std;

ProtoList::NonExistingElement::NonExistingElement(const string &__arg) : runtime_error(__arg) {}

const char *ProtoList::NonExistingElement::what() const noexcept {
    return "Element does not exist in the list";
}

ProtoList::Node::Node() = default;

ProtoList::Node::Node(int data) : data(data) { next = nullptr; }

int ProtoList::Node::getData() const {
    return data;
}

void ProtoList::Node::setData(int data) {
    Node::data = data;
}

ProtoList::Node *ProtoList::Node::getNext() const {
    return next;
}

void ProtoList::Node::setNext(ProtoList::Node *next) {
    Node::next = next;
}

//-----------------------------------------------------------------------------------

ProtoList::ProtoList() = default;

ProtoList::ProtoList(
        int data) { //Special case constructor where it is guaranteed that createNode function will always put this as first element
    createNode(data);
}

ProtoList::ProtoList(int *data, int arrSize) {
    parseArray(data, arrSize);
}

void ProtoList::parseArray(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; ++i)
        insertLast(arr[i]);
}

ProtoList::Node *ProtoList::createNode(int data) {

    auto *node = new Node(data);

    size = size + 1;

    if (HEAD == nullptr) {
        HEAD = node;
        TAIL = node;

        return nullptr;
    }

    return node;
}

void ProtoList::insertFirst(int data) {

    Node *node = createNode(data);

    if (node == nullptr)
        return;

    node->setNext(HEAD);
    HEAD = node;

}

void ProtoList::insertLast(int data) {

    Node *node = createNode(data);

    if (node == nullptr)
        return;

    TAIL->setNext(node);
    TAIL = node;


}

void ProtoList::insertPos(int data, int pos) {

    if (size - pos < 0 || pos < 0)
        throw out_of_range("Insertion position out of bounds");

    Node *node = createNode(data);

    if (node == nullptr)
        return;

    Node *current = HEAD;
    Node *previous = nullptr;

    for (int i = 1; i <= pos; ++i) {
        previous = current;
        current = current->getNext();
    }

    node->setNext(current);
    previous->setNext(node);

}

void ProtoList::deleteFirst() {

    if (size == 0)
        throw NonExistingElement("List is Empty");

    Node *node = HEAD;
    HEAD = HEAD->getNext();

    size = size - 1;

    delete node;
}

void ProtoList::deleteLast() {

    if (size == 0)
        throw NonExistingElement("List is Empty");

    Node *current = HEAD;
    Node *previous = nullptr;

    while ((current->getNext()) != nullptr) {
        previous = current;
        current = current->getNext();
    }

    TAIL = previous;
    previous->setNext(nullptr);

    size = size - 1;

    delete current;
}

void ProtoList::deletePos(int pos) {

    if (size == 0)
        throw NonExistingElement("List is Empty");
    else if (size - pos < 0 || pos < 0)
        throw out_of_range("Deletion position out of bounds");
    else if (pos == 0) {
        deleteFirst();
        return;
    } else if (pos == size - 1) {
        deleteLast();
        return;
    }

    Node *current = HEAD;
    Node *previous = nullptr;

    for (int i = 1; i <= pos; ++i) {
        previous = current;
        current = current->getNext();
    }

    previous->setNext(current->getNext());

    size = size - 1;

    delete current;
}

bool ProtoList::update(int data, int pos) {
    //Return false if updating of an element failed due to its absence
    if (size == 0 || size - pos < 0 || pos < 0)
        return false;

    Node *node = HEAD;

    for (int i = 1; i <= pos; ++i)
        node = node->getNext();

    node->setData(data);

    return true;
}

ProtoList::Node *ProtoList::get(int pos) {
    if (size == 0 || size - pos < 0 || pos < 0)
        return nullptr;

    Node *node = HEAD;

    for (int i = 1; i <= pos; ++i)
        node = node->getNext();

    return node;
}

int ProtoList::getSize() const {
    return size;
}

void ProtoList::display() const {
    Node *node = HEAD;

    while (node != nullptr) {
        if (node->getNext() != nullptr)
            cout << node->getData() << "->";
        else
            cout << node->getData() << "\n";

        node = node->getNext();
    }

    node = nullptr;
    delete node;
}