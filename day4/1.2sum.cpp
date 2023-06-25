//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;


// 1st Approach
vector<vector<int>> pairSum(vector<int> &a, int s){
    // -6 2 2 2 5
    // Write your code here.
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n-1; i++) {

        int start = i + 1;

        while (a[start] + a[i] <= s) {
            int sum = a[i] + a[start];

            if (sum == s) {
                ans.push_back({a[i], a[start]});

            }
            start++;
        }
    }
    return ans;

}



// 2nd approach
class Solution {
public:


    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numIndices.count(complement)) {
                return {numIndices[complement], i};
            }

            numIndices[nums[i]] = i;
        }

        return {};
    }
};