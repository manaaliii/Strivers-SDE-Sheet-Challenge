//
// Created by manal on 25-06-2023.
//

#include <bits/stdc++.h>
using namespace std;


// Coding Ninjas -- (x^n) % k
int modularExponentiation(int x, int n, int k) {
    long long int result = 1;
    long long int base = x % k;

    while(n>0){
        if(n % 2 == 1){
            result = (result*base) % k;
        }
        base = (base * base) % k;
        n/=2;
    }
    return result;

}


// LeetCode pow(x,n)
class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1;
        if(nn < 0){
            nn = nn* -1;
        }
        while(nn){
            if(nn%2 == 0){
                x *= x;
                nn /= 2;
            }
            else{
                ans *= x;
                nn--;
            }
        }
        if(n < 0){
            return 1/ans;
        }
        return ans;

    }
};