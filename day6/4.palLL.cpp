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


LinkedListNode<int> *rev(LinkedListNode<int> *x) {
    LinkedListNode<int> *prev = nullptr;
    LinkedListNode<int> *node = x;
    while (node) {
        LinkedListNode<int> *cur = node;
        node = node->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = rev(slow);
    while (slow && head) {
        if (slow->data != head->data)
            return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}