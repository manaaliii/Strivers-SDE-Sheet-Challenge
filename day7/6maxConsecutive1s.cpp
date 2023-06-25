//
// Created by manal on 25-06-2023.
//



#include <bits/stdc++.h>
using namespace std;


int longestSubSeg(vector<int> &a , int n, int k){
    // Write your code here.
    int i = 0, j = 0, cnt = 0, len = -1;
    while(j < n){
        if(!a[j]){
            cnt++;
            while(i < j && cnt > k){
                if(!a[i])
                    cnt--;
                i++;
            }
        }
        len = max(len, j - i +1);
        j++;


    }
    return len;

}

