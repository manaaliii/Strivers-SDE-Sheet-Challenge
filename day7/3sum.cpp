//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>a, int n, int k) {
    // Write your code here.
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(i > 0 && a[i] == a[i-1])
            continue;
        int j = i+1;
        int l = n - 1;
        while(j < l){
            int sum = a[i] + a[j] + a[l];

            if(sum == k){
                ans.push_back({a[i], a[j], a[l]});
                j++;
                l--;
            }
            else if(sum < k){
                j++;
            }
            else{
                l--;
            }
            while(l > -1 && j < l && a[l] == a[l+1])
                l--;
            while(j < n && j < l && j > i +1 && a[j] == a[j-1])
                j++;
        }

    }
    return ans;

    //-131 1 1 6 9 14 28 160
    //

}