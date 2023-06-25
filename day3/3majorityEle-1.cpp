//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;


// 1st approach
int findMajorityElement0(int a[], int n) {
    // Write your code here.
    map<int, int> mp;
    for(int i = 0; i < n ;i++){
        mp[a[i]]++;
        if(mp[a[i]] > n/2)
            return a[i];
    }
    return -1;
}

// 2nd approach (think it like if ele > n/2 exist it will cancel out all elements
int findMajorityElement1(int a[], int n){
    int count = 0;
    int ele;
    for(int i = 0; i < n; i++){
        if(count == 0){
            ele = a[i];
            count = 1;
        }
        else if(a[i] == ele){
            count++;
        }
        else{
            count--;
        }
    }
    if(count > 0){
        int tmp = 0;
        for(int i = 0; i <n; i++){
            if(a[i] == ele)
                tmp++;
            if(tmp > n /2)
                return a[i];
        }
    }
    return -1;
}