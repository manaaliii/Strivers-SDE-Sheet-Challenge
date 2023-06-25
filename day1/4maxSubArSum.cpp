#include <bits/stdc++.h>
using namespace std;



/*
 * Brute Force: just check all sub arrays and find maximum subarray...
 * for i -> 0 to n
 * * for j -> i to n
 * * * for k -> j to n
 * * * * sum+= a[k];
 * * * max = max(max,sum);
 * You can do it by 2 for loops
 * for i -> 0 to n
 * * for j -> i to n
 * * * sum+= a[j];
 * * * maxi = max(sum, a[j]);
 */

long long maxSubarraySum(int a[], int n)
{

    long long maxi = INT_MIN;
    long long sum =0;
    for(int i = 0; i < n; i++){
        if(a[i] + sum >= 0){
            sum += a[i];
            maxi = max(sum, maxi);
        }
        else if(a[i] + sum < 0){
            sum = 0;
        }
    }

    if(maxi < 0)
        return 0;
    return maxi;

}