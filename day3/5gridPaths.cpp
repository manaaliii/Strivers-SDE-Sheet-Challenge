//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>
using namespace std;

int path(int start,int end, int m, int n, vector<vector<int>>& dp){
    if(start == m-1 && end == n-1){
        return 1;
    }
    else if(start >= m || end >= n)
        return 0;
    else if(dp[start][end] != -1)
        return dp[start][end];
    else
        return dp[start][end] = path(start+1, end, m, n,dp) + path(start, end+1,m,n,dp);
}
int uniquePaths0(int m, int n) {


    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return path(0,0,m,n, dp);
}


// space optimized approach(as well time to
// permutation

int uniquePaths1(int m, int n) {

    // steps to be walked to reach end
    n += m - 2;
    int r = m - 1;
    double res = 1;
    for(int i = 1; i <= r; i++) {
        res= res * (n - r + i) / i;
    }
    return int(res);
}