//
// Created by manal on 25-06-2023.
//

#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int Count(Node * ptr){
    int c = 0;
    while(ptr){
        ptr = ptr->next;
        c++;
    }
    return c;
}

Node *rotate(Node *head, int k) {
    // Write your code here.
    if(k == 0)
        return head;
    int count = Count(head);
    if( k > count){
        while(k > count)
            k-=count;
        if(k == 0)
            return head;
    }

    int loop = count - k;
    Node * ptr = head;
    Node * ans;
    while(loop>0){
        ptr = ptr->next;
        loop--;
    }

    ans = ptr;
    Node * tmp = ans;
    while(tmp->next){
        tmp = tmp->next;
    }

    ptr = head;
    loop = count - k;
    while(loop--){
        tmp->next = ptr;
        tmp = tmp->next;
        ptr = ptr->next;
    }
    tmp->next = nullptr;
    return ans;


}
