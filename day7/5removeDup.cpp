//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>
using namespace std;


int removeDuplicates(vector<int> &a, int n) {
    int j = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1])
            continue;
        if(i < n)
            a[j++] = a[i];
    }
    return j;
}
