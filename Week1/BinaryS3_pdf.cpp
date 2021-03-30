//Majority element
#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int lside(int arr[],int f,int r,int x)
{
    int mid;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(x<=arr[mid])
        r = mid;
        else
        f = mid;
    }
    if(arr[f]==x)
    return f;
    else if(arr[r]==x)
    return r;
    else
    return -1;
}
int rside(int arr[],int f,int r,int x)
{
    int mid;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(x>=arr[mid])
        f = mid;
        else
        r = mid;
    }
    if(arr[r]==x)
    return r;
    else if(arr[f]==x)
    return f;
    else
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,4,4,4,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int mid = (n-1)/2;
    int ls = lside(arr,0,n-1,arr[mid]);
    int rs = rside(arr,0,n-1,arr[mid]);
    cout<<"count "<<rs-ls+1;

    return 1;
}