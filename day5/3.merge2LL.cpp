//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
//Following is the linked list node structure.

template<typename T>
class Node {
public:
    T data;
    Node *next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


Node<int> *sortTwoLists(Node<int> *first, Node<int> *second) {
    // Write your code here.
    Node<int> *ans = nullptr;
    if (first && second) {
        if (first->data <= second->data) {
            Node<int> *node = new Node<int>(first->data);
            first = first->next;
            ans = node;
        } else {
            Node<int> *node = new Node<int>(second->data);
            second = second->next;
            ans = node;
        }
    } else if (first) {
        return first;
    } else if (second) {
        return second;
    } else
        return nullptr;


    Node<int> *head = ans;
    while (first && second) {
        if (first->data <= second->data) {
            Node<int> *node = new Node<int>(first->data);
            first = first->next;
            ans->next = node;
            ans = ans->next;
        } else {
            Node<int> *node = new Node<int>(second->data);
            second = second->next;
            ans->next = node;
            ans = ans->next;

        }
    }
    while (first) {
        Node<int> *node = new Node<int>(first->data);
        first = first->next;
        ans->next = node;
        ans = ans->next;

    }
    while (second) {

        Node<int> *node = new Node<int>(second->data);
        second = second->next;
        ans->next = node;
        ans = ans->next;


    }
    return head;
}
