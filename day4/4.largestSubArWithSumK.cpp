//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;


// for 0
int LongestSubsetWithZeroSum(vector < int > a) {

    // Write your code here
    map<int, int> s;
    int ans = 0, sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
        if(sum == 0)
        {
            ans = 1 + i;
        }
        else{
            if(s.count(sum)){
                ans = max(ans, i - s[sum]);
            }
            else
                s[sum] = i;
        }
    }
    return ans;

}


// for k (no diff in code except one condition if sum is k)
int LongestSubsetWithKSum(vector < int > a, int k) {

    // Write your code here
    map<int, int> s;
    int ans = 0, sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
        if(sum == k)
        {
            ans = 1 + i;
        }
        else{
            if(s.count(sum)){
                ans = max(ans, i - s[sum]);
            }
            else
                s[sum] = i;
        }
    }
    return ans;

}