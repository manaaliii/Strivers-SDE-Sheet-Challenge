//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;


//using extra space
vector<int> ninjaAndSortedArrays(vector<int>& a1, vector<int>& a2, int m, int n) {
    // Write your code here.
    vector<int> ans;
    int i1 = 0, i2 = 0;
    while(i1 < m && i2 < n){
        if(a1[i1] <= a2[i2])
        {
            ans.push_back(a1[i1]);
            i1++;
        }
        else{
            ans.push_back(a2[i2]);
            i2++;
        }
    }

    while(i1 < m){
        ans.push_back(a1[i1]);
        i1++;

    }

    while(i2 < n){
        ans.push_back(a2[i2]);
        i2++;

    }
    return ans;
}


// another approach without extra space
class Solution {
public:

    void merge(vector<int>& a1, int m, vector<int>& a2, int n) {
        int i = m-1;
        int j = n - 1;
        int k = m + n -1;

        //compare from last elements and push them...
        while(j >= 0){
            if(i >= 0 && a1[i] > a2[j]){
                a1[k--] = a1[i--];
            }
            else{
                a1[k--] = a2[j--];
            }
        }
    }
};


