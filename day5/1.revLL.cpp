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


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    // Write your code here
    LinkedListNode<int> *prev = nullptr;
    LinkedListNode<int> *cur = head;

    while (cur) {
        LinkedListNode<int> *node = cur;
        cur = cur->next;
        node->next = prev;
        prev = node;
    }
    return prev;

}