//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;

// You can just iterate over all the elements and check cur +1, cur +2... exist(takes lot of time)

int lengthOfLongestConsecutiveSequence(vector<int> &a, int n) {
    // Write your code here.
    unordered_set<int> s;

    for(auto it : a)
        s.insert(it);
    int ans = 0;
    for(auto num: a){
        if(!s.count(num-1)){
            int cnum = num+1;
            int count = 1;
            while(s.count(cnum)){
                cnum++;
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;

}