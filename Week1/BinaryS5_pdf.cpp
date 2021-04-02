#include<bits/stdc++.h>
using namespace std;
 
void printUnsorted(int arr[], int n)
{
    int f,r,i,temp1,temp2;
    for (f = 0; f < n-1; f++)
    {
        if (arr[f] > arr[f+1])
        break;
    }
    if (f == n-1)
    {
        cout << "Array is sorted";
        return;
    }
    for(r = n - 1; r > 0; r--)
    {
        if(arr[r] < arr[r-1])
        break;
    }
    temp1 = arr[f];
    temp2 = arr[f];
    
    for(i = f + 1; i <= r; i++)
    {
        if(arr[i] > temp1)
        temp1 = arr[i];
        if(arr[i] < temp2)
        temp2 = arr[i];
    }
    for(i = 0; i < f; i++)
    {
        if(arr[i] > temp2)
        {
            f = i;
            break;
        }
    }
    for( i = n -1; i >= r+1; i--)
    {
        if(arr[i] < temp1)
        {
            r = i;
            break;
        }
    }
    cout<<f <<"-"<< r;
    return;
}
 
int main()
{
    int arr[] = {1,2,3,0,5,6,-1,10,12,13,14};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    notsorted(arr, arr_size);
    return 0;
}