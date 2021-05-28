#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void permutation(string str,int low,int high)
{
    if(low == high)
    cout<<str<<"\n";

    for(int i=low;i<=high;i++)
    {
        swap(str[low],str[i]);
        permutation(str,low+1,high);
        swap(str[low],str[i]);
    }
}

int main()
{
    string str = "abcdef";
    int n = str.length();
    permutation(str,0,n-1);
    return 0;
}
