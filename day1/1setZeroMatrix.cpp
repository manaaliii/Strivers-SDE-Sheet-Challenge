//
// Created by manal on 05-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int vis[n][m];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0 & !vis[i][j]){
                vis[i][j] = 1;
                for(int c = 0; c<m;c++)
                    matrix[i][c]=0;
                for(int r = 0; r < n; r++)
                    matrix[r][j] = 0;

            }
        }
    }
}

void setZeroess(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j < m; j++){
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(int j = 0; j < n; j++){
            matrix[j][0] = 0;
        }
    }

}

int main(){
    vector<vector<int>> m;

}