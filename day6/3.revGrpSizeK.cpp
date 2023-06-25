//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>

using namespace std;


//    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


int countNode(Node *h) {
    Node *p = h;
    int c = 0;
    while (p) {
        p = p->next;
        c++;
    }
    return c;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]) {
    // Write your code here.
    if (head == NULL || head->next == NULL) return head;

    Node *node = new Node(0);
    node->next = head;
    Node *prev = node;
    Node *cur;
    Node *next;
    int len = countNode(head);

    for (int i = 0; i < n; i++) {

        if (b[i] == 1) {
            prev = prev->next;
            len--;
            continue;
        }
        if (len >= b[i] && b[i]) {

            cur = prev->next;
            next = cur->next;
            for (int j = 1; j < b[i]; j++) {


                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = cur->next;
            }

            prev = cur;
            len -= b[i];

        } else if (b[i] && len > 1) {
            cur = prev->next;
            next = cur->next;
            for (int j = 1; j < len; j++) {


                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = cur->next;
            }
            break;

        } else if (len == 0 || len == 1)
            break;

    }

    return node->next;

}