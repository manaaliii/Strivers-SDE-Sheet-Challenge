//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace  std;


// very similar to subarray of k sum..
// x ^ k = xr
// x ^ k ^ k = xr ^ k
// x = xr ^ k
int subarraysXor(vector<int> &a, int k)
{
    //    Write your code here.
    map<int, int> m;
    long n = a.size();
    int xr = 0;
    m[xr]++;
    int ans = 0;
    for(int i = 0; i < n; i++){
        xr ^= a[i];

        int x = xr ^ k;
        ans += m[x];
        m[xr]++;

    }
    return ans;
}