//
// Created by manal on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;

//1st approach

void assign(int *a,int s, int l, int val){
    for(int i = s; i < l; i++)
        a[i] = val;
}
void sort012(int *a, int n)
{
    //   Write your code here

    int c0 = 0, c1=0,c2=0;
    for(int i = 0; i < n;i++){
        if(a[i] == 0)
            c0++;
        else if(a[i] == 1)
            c1++;
        else
            c2++;
    }
    assign(a, 0, c0, 0);
    assign(a, c0, c1+c0, 1);
    assign(a, c1+c0, n, 2);
}


//1nd approach

void sort012_(int * a, int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid <= high){

        if(a[mid] == 0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }else if(a[mid] == 1){
            mid++;
        }else if(a[mid] == 2){
            swap(a[high],a[mid]);
            high--;
        }
    }

}