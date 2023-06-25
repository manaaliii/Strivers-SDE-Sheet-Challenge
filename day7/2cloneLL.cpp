//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>

using namespace std;

//    Following is the LinkedListNode class structure

template<typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;

    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
    // Write your code here.
    if (!head)
        return head;
    LinkedListNode<int> *tmp = head;
    while (tmp) {
        LinkedListNode<int> *n = new LinkedListNode<int>(tmp->data);
        n->next = tmp->next;
        tmp->next = n;
        tmp = tmp->next->next;
    }

    LinkedListNode<int> *itr = head;
    while (itr) {
        if (itr->random) {
            itr->next->random = itr->random->next;
        } else
            itr->next->random = nullptr;
        itr = itr->next->next;
    }
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    itr = head;
    tmp = dummy;
    LinkedListNode<int> *fast;
    while (itr) {
        fast = itr->next->next;
        tmp->next = itr->next;
        itr->next = fast;
        tmp = tmp->next;
        itr = fast;
    }
    return dummy->next;
}
