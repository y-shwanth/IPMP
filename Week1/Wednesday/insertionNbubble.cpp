#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertionsort(int arr[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i - 1;
        while(j!=-1)
        {
            if(arr[j]>arr[i])
            {
                arr[j + 1] = arr[j];
                --j;
            }
        }
        j++;
        arr[j] = temp; 
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
void bubblesort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {2,5,1,6,0};
    int arr1[] = {2,5,1,6,0};
    int n=5;
    insertionsort(arr,n);
    bubblesort(arr1,n);
    return 1;

}