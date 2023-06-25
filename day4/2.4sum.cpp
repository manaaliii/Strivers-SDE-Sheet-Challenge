//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>
using namespace std;

// You can use 4 loops to check for target


// Optimized approach (2 for loops and 2 pointers(very similar to 3 sum))

string fourSum(vector<int> a, int target, int n) {
    // Write your code here.
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i] == a[i+1])
            continue;
        for(int j = i +1; j < n  ; j++){
            int k = j +1;
            int l = n-1;
            while(k < l){
                long long sum = (long long)(a[i] +a[j] +a[k] +a[l]);
                if(sum == target){
                    return "Yes";
                }
                else if(sum > target)
                    l--;
                else
                    k++;
            }

        }
    }
    return "No";
}
