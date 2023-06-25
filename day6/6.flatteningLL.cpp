//
// Created by manal on 25-06-2023.
//


//  Definition for linked list.



#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node * merge2list(Node * a, Node *b){
    a->next = NULL;
    b->next = NULL;
    Node * tmp = new Node(0);
    Node * res = tmp;
    while(a && b){
        if(a->data < b->data){
            tmp->child = a;
            a = a->child;
        }else{
            tmp->child = b;
            b = b->child;
        }
        tmp = tmp->child;
    }

    if(a) tmp->child = a;
    else tmp->child = b;


    return res->child;
}

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        // Comparison function for priority queue
        return a->data > b->data;
    }
};

Node* flattenLinkedList(Node* head)
{
    // Write your code here
    priority_queue<Node*, std::vector<Node*>, NodeComparator> pq;

    Node * ptr = head;
    while(ptr){
        pq.push(ptr);
        ptr = ptr->next;

    }

    Node * tmp = new Node(0);
    Node * ans = tmp;


    while(!pq.empty()){
        Node * t = pq.top();
        if(t->next)
            t->next = nullptr;
        tmp->child = t;
        tmp = tmp->child;
        pq.pop();
        Node * ch = t->child;
        if(ch){
            pq.push(ch);
            ch = ch->child;
        }

    }
    return ans->child;
}
