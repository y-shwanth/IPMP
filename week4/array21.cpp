#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(int a[], int n)
{
    int i = 0, start = 0, end = n - 1, left_sum = 0,right_sum = 0;
    for (i = 0; i < n; i++) 
    {    
        if (start == end && right_sum == left_sum)
            return a[start];
        if (start == end)
            return -1;
 
        if (left_sum > right_sum) 
        {
            right_sum += a[end];
            end--;
        }
        else if (right_sum > left_sum) 
        {
            left_sum += a[start];
            start++;
        }
        else 
        {
            right_sum += a[end];
            end--;
        }
    }
 
    if (!i) 
    {
        return a[0];
    }
}

int main()
{
    int arr[] = { 2, 3, 4, 1, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << (equilibriumPoint(arr, size));
}
