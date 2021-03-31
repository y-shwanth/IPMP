#include<bits/stdc++.h>
using namespace std;

void swap (int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[],int f,int r)
{
    int pivot = r;
    int i= f-1;
    int j = f;
    while(j!=r)
    {
        if(arr[j]<arr[pivot])
        {
            ++i;
            swap(&arr[i],&arr[j]);
        }
        ++j;
    }
    swap(&arr[i+1],&arr[j]);
    return i+1;
}

void quicksort(int arr[],int f,int r)
{
    if(f<r)
    {
        int pi = partition(arr,f,r);
        quicksort(arr,f,pi-1);
        quicksort(arr,pi+1,r);
    }
}

int main()
{
    int arr[] = {5,6,1,9,4,7,2,12,10};
    int f=0,r=8;
    quicksort(arr,f,r);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 1;
}