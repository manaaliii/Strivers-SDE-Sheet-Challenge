//
// Created by manal on 25-06-2023.
//


#include<bits/stdc++.h>

using namespace std;


//    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        next = NULL;
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


bool detectCycle(Node *head) {
    //	Write your code here
    if (!head->next)
        return false;

    Node *fast = head;
    Node *slow = head;
    do {
        slow = slow->next;
        fast = fast->next->next;


    } while (fast && fast->next && slow != fast);


    return fast && fast->next;

}