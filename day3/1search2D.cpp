//
// Created by manal on 25-06-2023.
//
#include<bits/stdc++.h>
using namespace std;


// 1st method
bool searchEle(vector<vector<int>>& a, int i, int h, int target){
    int mid;
    int l = 0;
    while(l < h){
        mid = (l + h)/ 2;
        if(a[i][mid] == target)
            return true;
        else if(a[i][mid] > target)
            h--;
        else
            l++;
    }
    return false;
}

bool searchMatrix0(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
        if(target >= mat[i][0] && target <= mat[i][m-1]){
            return searchEle(mat, i, m, target);
        }
    }
    return false;

}

// another approach

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int low = 0;
    if(!matrix.size())
        return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int high = (n * m) - 1;

    while(low <= high){
        int mid = (low + (high - low) / 2);
        if(matrix[mid/m][mid % m] == target){
            return true;
        }
        if(matrix[mid/m][mid % m] > target){
            high = mid - 1;
        }
        else
            low = mid + 1;

    }
    return false;
}