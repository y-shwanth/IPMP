#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

void bisearch(int arr[],int f,int r,int x)
{
    int fi = f, ri = r;
    int mid;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(arr[mid]>x)
        r = mid;
        else
        f = mid;
    }
    if(x < arr[fi])
    cout<<"floor does'nt exist\n"<<"ceil "<<arr[f];
    else if(x > arr[ri])
    cout<<"floor "<<arr[r]<<"\nceil does'nt exist";
    else
    cout<<"floor "<<arr[f]<<"\nceil "<<arr[r];
}

int main()
{
    int arr[] = {1,2,8,10,10,12,19};
    int n = sizeof(arr)/sizeof(int);
    bisearch(arr,0,n-1,20);
    return 1;

}