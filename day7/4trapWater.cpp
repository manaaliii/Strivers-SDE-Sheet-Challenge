//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;

long getTrappedWater(long *a, int n){
    // Write your code here.
    int l = 0, r = n - 1;
    long leftMax = 0, rightMax =0;
    long ans = 0;
    while(l <= r){
        if(a[l] <= a[r]){
            if(a[l] >= leftMax)
                leftMax = a[l++];
            else
                ans += (leftMax - a[l++]);
            continue;
        }
        if(a[r] >= rightMax)
            rightMax = a[r--];
        else
            ans += (rightMax-a[r--]);

    }
    return ans;
}