#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int usualbis(int arr[],int f,int r,int x)
{
    int mid;
    while(r>=f)
    {
        mid = f + (r-f)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[mid]>x)
        r = mid - 1;
        else
        f = mid + 1;
    }
    return -1;
}

int bisearch(int arr[],int f,int r,int x)
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

int mincase1(int arr[],int f,int r)
{
    int mid,min;
    min = INT_MAX;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(arr[mid]<min)
        {
            min = arr[mid];
            r = mid;
        }
        else
        f = mid;
    }
    return r;
}

int maxcase2(int arr[],int f,int r)
{
    int mid,max;
    max = INT_MIN;
    while(r - f > 1)
    {
        mid = f + (r - f)/2;
        if(arr[mid]>max)
        {
            max = arr[mid];
            f = mid;
        }
        else
        r = mid;
    }
    return r;
}



int main()
{
    int arr[] = {6,7,0,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    /*int rv = usualbis(arr,0,n-1,11);
    cout<<"index "<<rv;
    rv = bisearch(arr,0,n-1,9);
    cout<<"\nindex "<<rv;
    */
    /*
    int ls = lside(arr,0,n-1,5);
    int rs = rside(arr,0,n-1,5);
    cout<<"\ncount "<<rs -ls +1;
    */
    int c1 = mincase1(arr,0,n-1);
    int c2 = maxcase2(arr,0,n-1);
    if(c1-1 == 0)
    {
        if(c2==n-1)
        cout<<"Rotated at index "<<(n-1)/2;
        cout<<"Rotated at index "<<c2;
    }
    else
    cout<<"Rotated at index "<<c1;
    return 1;
}
