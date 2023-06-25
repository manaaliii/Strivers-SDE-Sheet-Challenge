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


int count(Node *p) {
    int ans = 0;
    while (p) {
        // cout<<p->data<<" ";
        p = p->next;
        ans++;
    }
    // cout<<endl;
    return ans;
}

int diff(int l1, int l2) {
    // cout<<c1<<" "<<c2<<endl;
    return l1 - l2;
}

Node *findIntersection(Node *f1, Node *f2) {

    int c1 = count(f1);
    int c2 = count(f2);
    int _diff = diff(c1, c2);
    if (_diff < 0) {
        while (_diff++)
            f2 = f2->next;
    } else if (_diff > 0) {
        while (_diff--)
            f1 = f1->next;
    }
    while (f1 && f2) {
        if (f1 == f2)
            return f1;
        f1 = f1->next;
        f2 = f2->next;
    }
    return nullptr;


}