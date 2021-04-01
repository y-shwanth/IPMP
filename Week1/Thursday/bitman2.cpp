#include<bits/stdc++.h>
using namespace std;

void func(unsigned int x)
{
    int n = 32;
    unsigned int temp = 0;
    for(int i=0;i<n;i++)
    {
        if((x & (1<<i)))
        temp |= 1<<((n-1)-i);
    }
    cout<<temp;
}
void func2(unsigned int x)
{
    int count = 31;
    unsigned int temp = x;
    x >>= 1;
    while(x)
    {
        temp <<= 1;
        temp |= x&1;
        x >>= 1;
        --count;
    }
    temp <<= count;
    cout<<"\nfunc2 "<<temp;
}
int main()
{
    unsigned int x = 2;
    func(x);
    func2(x);
    return 1;
}