#include <bits/stdc++.h>
using namespace std;

bool compare(int x, int y)
{
    return abs(x) < abs(y);
}
 
void findMinSum(int arr[], int n)
{
    sort(arr, arr + n, compare);
    int min = INT_MAX, x, y;
    for (int i = 1; i < n; i++) 
    {
        if (abs(arr[i - 1] + arr[i]) <= min) 
        {
            min = abs(arr[i - 1] + arr[i]);
            x = i - 1;
            y = i;
        }
    }
    cout << "The two elements whose sum is minimum are "<< arr[x] << " and " << arr[y];
}

int main()
{
 
    int arr[] = { 1, 99, -1, 60, -81, 53 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMinSum(arr, n);
    return 0;
}
