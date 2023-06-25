//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int buy = INT_MAX;
    int profit = 0;
    for(int price : prices){
        if(buy > price){
            buy = price;
        }
        if( price - buy> profit){
            profit = price-buy;

        }
    }
    return profit;

}