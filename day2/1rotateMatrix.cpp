//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;


// Coding Ninjas - rotate matrix elements clockwise direction (one step only)
void rotateMatrix(vector<vector<int>> &m, int n, int mm)
{
    int r = 0;
    int c = 0;
    int mr = n-1;
    int mc = mm-1;
    while(r < mr && c < mc){

        int prev = m[r+1][c];
        for(int i = c; i <= mc; i++){
            int curr = m[r][i];
            m[r][i] = prev;
            prev = curr;
        }

        r++;
        for(int i = r; i <= mr; i++){
            int curr = m[i][mc];
            m[i][mc] = prev;
            prev = curr;
        }


        mc--;
        if(r<mr+1){
            for(int i = mc; i >= c; i--){
                int curr = m[mr][i];
                m[mr][i] = prev;
                prev = curr;
            }
            mr--;
        }

        if(c < mc+1){
            for(int i = mr; i >= r; i--){
                int curr = m[i][c];
                m[i][c] = prev;
                prev = curr;
            }
            c++;
        }

    }

}

// Leet Code - rotate matrix at 90 degree clock wise

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        int ind = n-1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][ind];
                matrix[i][ind] = temp;
                ind--;
            }
            ind = n-1;
        }
    }
};