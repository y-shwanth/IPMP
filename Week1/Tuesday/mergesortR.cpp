#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int f,int m,int r)
{
    int n1 = m-f+1;
    int n2 = r-m;
    int i,j;
    int ls[n1],rs[n2];
    for(i=0;i<n1;i++)
    ls[i] = arr[f+i];  
    for(j=0;j<n2;j++)
    rs[j] = arr[m+1+j];

    int k=f; i=j=0;
    while(i<n1 && j<n2)
    {
        if(ls[i]<=rs[j]) 
        {
            arr[k] = ls[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = rs[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k] = ls[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = rs[j];
        k++;
        j++;
    }
}

void mergesort(int arr[],int f, int r)
{
    if(f>=r)
    return;
    int mid = f + (r-f)/2;
    mergesort(arr,f,mid);
    mergesort(arr,mid+1,r);
    merge(arr,f,mid,r);
}

int main()
{
    int arr[] ={5,1,9,2,6,8,3,12,10};
    int f=0,r=8;
    mergesort(arr,f,r);
    for(int i=0;i<9;i++)
    cout<<arr[i]<<" ";
    return 0;
}