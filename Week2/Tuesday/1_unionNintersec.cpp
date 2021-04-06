#include<bits/stdc++.h>
#include<vector>
using namespace std;

void intersec(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> v;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            ++i;
        }
        else if(arr1[i] > arr2[j])
        {
            ++j;
        }
        else
        {
            v.push_back(arr1[i]);
            ++i;
            ++j;
        }
    }
    cout<<"\n\nIntersection\n";
    for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}



void _union(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> v;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            v.push_back(arr1[i]);
            ++i;
        }
        else if(arr1[i] > arr2[j])
        {
            v.push_back(arr2[j]);
            ++j;
        }
        else
        {
            v.push_back(arr1[i]);
            ++i;
            ++j;
        }
    }

    while(i<n1)
    {
        v.push_back(arr1[i]);
        ++i;
    }
    while(j<n2)
    {
        v.push_back(arr2[j]);
        ++j;
    }

    cout<<"\nUnion\n";
    for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}

int main()
{
    int arr1[] = {5,6,7,8,9,10};
    int arr2[] = {2,3,4,5,6,7};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    _union(arr1,arr2,n1,n2);
    intersec(arr1,arr2,n1,n2);
}