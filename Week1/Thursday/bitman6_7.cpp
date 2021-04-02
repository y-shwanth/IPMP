#include<bits/stdc++.h>
using namespace std;

void turnoffRMSB(unsigned int y)
{
    cout<<"\n"<<(y&(y-1));
}

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
    unsigned int y = 7;
    absolute(x);
    turnoffRMSB(y);
    return 1;
}