//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

long long merge(long long *a, int l, int h, int m) {
    if (l >= h)
        return 0;
    long long count = 0;
    int left = l, r8 = m+1;
    vector<long long> t;
    while(left <= m && r8 <= h){
        if(a[left] <= a[r8])
            t.push_back(a[left++]);
        else
        {
            t.push_back(a[r8++]);
            count += ((long long)m - (long long)left + 1LL);
        }
    }
    while(left <= m){
        t.push_back(a[left++]);

    }
    while(r8 <= h){
        t.push_back(a[r8++]);
    }

    for(int i = l ;i <= h; i++){
        a[i] = t[i - l];
    }



    return count;
}

long long mergeSort(long long *a, int l,int h){
    if(l>=h)
        return 0;
    int m = (h + l) / 2;
    long long ans = mergeSort(a, l, m);
    ans += mergeSort(a, m+1, h);
    ans += merge(a, l, h, m);
    return ans;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}