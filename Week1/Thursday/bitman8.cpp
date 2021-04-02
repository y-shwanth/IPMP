#include <bits/stdc++.h>
using namespace std;
 
void add(int x, int y)
{
    while (y != 0)
    {
        int carry = x & y;
        x = x^y;
        y = carry << 1;
    }
    cout<<x;
}

int main()
{
    add(23,44);
    return 0;
}