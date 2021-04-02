#include<bits/stdc++.h>
using namespace std;

void absolute(int x)
{
    int temp = -1;
    temp >>= 31;
    x = x^temp;
    x = x + 1;
    cout<<x;
}

int main()
{
    int x = -23;
    absolute(x);
    return 1;
}