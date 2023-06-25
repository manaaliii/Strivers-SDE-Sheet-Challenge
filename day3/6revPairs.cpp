//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

int merge(int l, int h, int m,vector<int> &a){
    if(l >= h)
        return 0;
    int j = m +1;
    int ret = 0;
    for(int i = l; i<=m;i++){
        long long int t = 2 * static_cast<long long int>(a[j]);
        while(j <= h && a[i] >  t){
            j++;
            t = 2 * static_cast<long long int>(a[j]);
        }
        ret += (j - (m+1));
    }

    vector<int> aa;
    int left = l, right = m+1;
    while(left<=m && right <=h){
        if(a[left] <= a[right])
            aa.push_back(a[left++]);
        else
            aa.push_back(a[right++]);
    }


    while(left<=m){
        aa.push_back(a[left++]);
    }


    while(right <=h){
        aa.push_back(a[right++]);
    }
    for(int i = l; i <=h; i++){
        a[i] = aa[i - l];
    }

    return ret;
}
int mergeSort(int l, int h, vector<int> &a){
    if(l >=h)
        return 0;
    int m = (l+h)/2;
    int c = mergeSort(l, m, a);
    c += mergeSort(m+1, h, a);
    c += merge(l, h, m, a);
    return c;
}

int reversePairs(vector<int> &a, int n){
    // Write your code here.
    return mergeSort(0, a.size()-1, a);
}