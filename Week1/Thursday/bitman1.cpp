#include<bits/stdc++.h>
using namespace std;

bool func(int x)
{
    return !(x & (x-1)); 
}

int main()
{
    int x = 128;
    if(x!=0)
    {
        if(func(x))
        {
            cout<<"YES";
            return 1;
        }
    }
    cout<<"NO";
    return 1;
}