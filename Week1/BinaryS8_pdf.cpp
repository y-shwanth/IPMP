//increasing then decreasing
#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int max(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}

int incside(int arr[],int f,int r)
{
    int mid;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(arr[mid]<arr[r])
        f = mid;
        else
        r = mid;
    }
    return max(arr[f],arr[r]);
}

int decside(int arr[],int f,int r)
{
    int mid;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(arr[mid]<arr[f])
        r = mid;
        else
        f = mid;
    }
    return max(arr[f],arr[r]);
}

int main()
{
    int arr[] = {1,30,40,50,60,70,23,20};
    int n = sizeof(arr)/sizeof(int);
    int mid = (n-1)/2;
    int incmax = incside(arr,0,mid);
    int decmax = decside(arr,mid,n-1);

    int finalmax = max(incmax,decmax);
    cout<<"MAX "<<finalmax;
}