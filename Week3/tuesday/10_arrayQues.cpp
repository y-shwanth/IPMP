#include<bits/stdc++.h>
using namespace std;

void find2number(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp = sum - arr[i] - arr[j];
            if(s.find(temp) != s.end())
            {
                cout<<"\n"<<arr[i]<<" "<<arr[j]<<" "<<temp;
                return;
            }
            s.insert(arr[j]);
        }
    }
    return;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(int);
    int sum = 22;
    find2number(arr,n,sum);
    return 1;
}