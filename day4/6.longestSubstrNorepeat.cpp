//
// Created by manal on 25-06-2023.
//


#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    //Write your code here
    map<char, int> m;
    int n = input.size();
    int i = 0,j = 0;
    int ans = 0;
    while(j < n){
        if(m[input[j]]){
            i = max(m[input[j]] + 1, i);
        }

        // storing index like whenever repeating character occurs
        m[input[j]] = j;
        ans = max(ans, j - i +1);
        j++;
    }
    return ans;
}