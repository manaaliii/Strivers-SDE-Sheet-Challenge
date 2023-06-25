//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

int Count(Node * h){
    Node * p = h;
    int ans = 0;
    while(p){
        p = p->next;
        ans++;
    }
    return ans;
}

Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    Node * ptr = head;
    int count = Count(head);
    int c = count - k + 1;
    if(c == 1)
        return head->next;
    while(c > 2){
        ptr = ptr->next;
        c--;
    }
    ptr->next = ptr->next->next;
    return head;


}
