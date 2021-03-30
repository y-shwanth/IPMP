//arr[i]=i
#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int fixedpoint(int arr[],int f,int r)
{
    int mid;
    while(f<=r)
    {
        mid = f + (r-f)/2;
        if(arr[mid]==mid)
        return mid;
        else if (arr[mid]>mid)
        r = mid - 1;
        else
        f = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[]={-1,0,1,2,3,4,5,6,7,9,11};
    int n = sizeof(arr)/sizeof(int);
    int x = fixedpoint(arr,0,n-1);
    cout<<"index "<<x;

    return 1;

}