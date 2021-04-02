#include<bits/stdc++.h>
using namespace std;

void nibbleswap(unsigned int x)
{
    cout<<"\n"<<(((x & 0x0f)<< 4) | ((x & 0xf0)>>4));
}

void only_setbit(unsigned int x)
{
    cout<<"\n"<<log2(x) + 1;
}

void swap_evodd(unsigned int x)
{
    unsigned int a = 0xAAAAAAAA,b = 0x55555555;
    a = a & (x<<1);
    b = b & (x>>1);
    cout<<"\n"<<(a|b);

}

void RMSBpos(unsigned int x)
{
    cout<<log2(x^(x&(x-1))) + 1;
}

int main()
{
    unsigned int x = 52,y = 23,z = 64;
    RMSBpos(x);
    swap_evodd(y);
    only_setbit(z);
    nibbleswap(100);
    return 1;
}