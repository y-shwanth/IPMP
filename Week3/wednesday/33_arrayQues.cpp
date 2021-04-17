#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void rearrange(char arr[], int n)
{
    int i=-1;
    for (int j = 0; j < n; j++)
    {
        if (isalpha(arr[j]))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int main()
{
    char arr[] = {'a','1','b','2','c','3','d','4'};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr,n);
    return 1;
}