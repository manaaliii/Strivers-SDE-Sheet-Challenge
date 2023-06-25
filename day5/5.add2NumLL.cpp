//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};


Node *addTwoNumbers(Node *l1, Node *l2) {
    Node *sum = nullptr;
    int carry = 0;
    if (l1 && l2) {
        int s = l1->data + l2->data;
        carry = s / 10;
        Node *node = new Node(s % 10);
        l1 = l1->next;
        l2 = l2->next;
        sum = node;
    } else if (l1) {
        return l1;
    } else if (l2) {
        return l2;
    } else {
        return nullptr;
    }
    Node *ans = sum;

    while (l1 && l2) {
        int s = l1->data + l2->data + carry;
        carry = s / 10;
        Node *node = new Node(s % 10);
        l1 = l1->next;
        l2 = l2->next;
        sum->next = node;
        sum = sum->next;
    }
    while (l1) {
        int s = l1->data + carry;
        carry = s / 10;
        Node *node = new Node(s % 10);
        l1 = l1->next;
        sum->next = node;
        sum = sum->next;

    }

    while (l2) {
        int s = l2->data + carry;
        carry = s / 10;
        Node *node = new Node(s % 10);
        l2 = l2->next;
        sum->next = node;
        sum = sum->next;

    }

    if (carry) {
        Node *node = new Node(carry);
        sum->next = node;
        sum = sum->next;

    }
    return ans;
}
