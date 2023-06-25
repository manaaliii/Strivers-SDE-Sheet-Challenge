//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>

using namespace std;





//    Following is the class structure of the LinkedListNode class:

template<typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

// first method
void deleteNode0(LinkedListNode<int> *node) {
    // Write your code here.
    LinkedListNode<int> *prev = nullptr; // used for repointing
    LinkedListNode<int> *cur = node;
    while (cur->next != nullptr) {
        cur->data = cur->next->data;
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;

}


// another method
void deleteNode1(LinkedListNode<int> *node) {
    *node = *node->next;
}