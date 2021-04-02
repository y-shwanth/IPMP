#include<stdlib.h>
#include<stdio.h>

int min(int x,int y)
{
    if(x>y)
    return x;
    elsereturn y;
}

void mergeSort(int arr[], int n)
{
   int current_size; 
   int ls; 
   for (current_size=1; current_size<=n-1; current_size = 2*current_size)
   {
       for (ls=0; ls<n-1; ls += 2*current_size)
       {
           int mid = min(ls + current_size - 1, n-1);
           int rs = min(ls + 2*current_size - 1, n-1);
           merge(arr,ls,mid,rs);
       }
   }
}
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


int main()
{
    int arr[] = {5,6,1,9,4,7,2,12,10};
    int f=0,r=8;
    mergesort(arr,f,r);
    for(int i=0;i<9;i++)
    cout<<arr[i]<<" ";
    return 0;
}