//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

// do mapping and see where map is > 1 and map val is 0;
pair<int,int> missingAndRepeating0(vector<int> &a, int n){
    map<int,int> mp;
    pair<int,int> tmp;
    for(int i = 1; i <= n;i++){
        mp[i] = 0;
    }
    for(int i = 0; i < n;i++){
        mp[i]++;
    }

    for(int i = 1; i <= n; i++){
        if(mp[i] == 2)
        {
            tmp.first = i;
        }
        if(mp[i] == 0)
        {
            tmp.second = i;
        }


    }
    return tmp;
}



// another space optimized approach
pair<int,int> missingAndRepeating1(vector<int> &a, int n)
{
    // Write your code here
    pair<int,int> ans;
    long long s1 = (n*(n+1))/2;
    long long s2 = ((long long)n*((long long)(n+1)*(long long)(2*n+1)))/6;

    long long S1 = 0, S2=0;
    for(int i = 0; i<n;i++){
        S1 += (long long) a[i];
        S2 += (long long)a[i]*a[i];
    }

    long long eq1 = s1 - S1;
    long long t_eq2 = s2 - S2;
    long long eq2 = t_eq2/eq1;

    int x = (eq1 + eq2)/2;
    int y = x - eq1;
    ans = {x,y};
    return ans;

}
