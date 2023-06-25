//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

// 1st method
vector<int> majorityElementII0(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    vector<int> ans;
    int mini = int(n/3) + 1;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        if(mp[a[i]] == mini)
            ans.push_back(a[i]);
        if(ans.size() == 2)
            break;
    }
    return ans;

}


// 2nd method (space optimized)
vector<int> majorityElementII1(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int c1 = 0, c2=0;
    int e1, e2;
    for(int i = 0; i < n; i++){
        if(c1 == 0 && e2 != a[i]){
            c1++;
            e1 = a[i];
        }
        else if(c2 ==0 && e1 != a[i]){
            c2++;
            e2 = a[i];
        }
        else if(a[i] == e1){
            c1++;
        }
        else if(a[i] == e2){
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1 = 0, c2=0;
    for(int i = 0; i<n;i++){
        if(a[i] == e1)
            c1++;
        else if(a[i] == e2)
            c2++;

    }
    if(c1 > n/3)
        ans.push_back(e1);
    if(c2 > n/3)
        ans.push_back(e2);
    return ans;
}