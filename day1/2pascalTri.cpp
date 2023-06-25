//
// Created by manal on 05-06-2023.
//

#include <bits/stdc++.h>
using namespace std;



// 1st approach

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;
    ans.push_back({1});
    if(n > 1)
        ans.push_back({1 , 1});
    for(int i = 2; i < n;i++){
        vector<long long int> tmp;
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                tmp.push_back(1);
            else
                tmp.push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        ans.push_back(tmp);
    }
    return ans;
}


// 2nd approach

vector<long long int> genRow(int m){
    long long int ans = 1;
    vector<long long int> a;
    a.push_back(ans);
    for(int i = 1; i < m; i++){
        ans *= (m - i);
        ans /= i;
        a.push_back(ans);
    }
    return a;
}

vector<vector<long long int>> pas(int n){
    vector<vector<long long int>> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back(genRow(i));
    }
    return ans;
}

