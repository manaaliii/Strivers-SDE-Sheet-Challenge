//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;


//1st approach
int findDuplicate0(vector<int> &a, int n){
    sort(a.begin(),a.end());
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1])
            return a[i];
    }
    return -1;
}


//2nd approach (inspired from linked list--slow and fast pointers...(cycle detection method))
//like for duplicates in array there will be cycle in array
int findDuplicate1(vector<int> &a, int n){
    int s = a[0];
    int f = a[0];
    do{
        s= a[s];
        f = a[a[f]];
    }while(s!=f);
    f = a[0];
    while(s!=f){
        s = a[s];
        f = a[f];
    }

    return s;


}
