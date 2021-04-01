#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[],int size,int root)
{
    int max = root;
    int l = 2*root + 1;
    int r = 2*root + 2;

    if(l<size && arr[l]>arr[max])
    max = l;
    if(r<size && arr[r]>arr[max])
    max = r;

    if(max!=root)
    {
        swap(&arr[max],&arr[root]);
        heapify(arr,size,max);
    }
}

void heapsort(int arr[],int n)
{
    int i;
    for(i = n/2 -1;i>=0;i--)
    heapify(arr,n,i);

    for(i=n;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }

    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int arr[] = {5,8,1,9,3,2,6};
    int n = sizeof(arr)/sizeof(int);
    heapsort(arr,n);
    return 1;
}