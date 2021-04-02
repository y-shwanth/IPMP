#include<bits/stdc++.h>
using namespace std;

void func2(unsigned int x)
{
    int count = 0;
    while(x)
    {
        x = x&(x-1);
        ++count;
    }
    cout<<"\n"<<count;
}
void func(unsigned int x)
{
    unsigned int temp;
    int count = 0;
    while(x)
    {
        temp = x&1;
        if(temp == 1)
        ++count;
        x >>= 1;
    }
    cout<<count;
}

int main()
{
    unsigned int x= 15;
    func(x);
    func2(19);
    return 1;
}