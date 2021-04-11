#include<bits/stdc++.h>
using namespace std;

void non_repeating(int arr[], int size)
{
    int xor_val = arr[0];
    int i;
    for(i=1;i<size;i++)
    {
        xor_val = xor_val^arr[i];
    }
    int rMsetbit = xor_val & ~(xor_val - 1);

    int x=0,y=0;
    for(i=0;i<size;i++)
    {
        if(rMsetbit & arr[i])
        x = x^arr[i];
        else
        y = y^arr[i];
    }
    cout<<x<<" "<<y;
}

int main()
{
    int arr[] = {3,4,7,1,12,3,4,12};
    int size = sizeof(arr)/sizeof(int);
    non_repeating(arr,size);
    return 1;
}