#include<bits/stdc++.h>
using namespace std;

void rightShift(unsigned int x, int count)
{
    x = ((x>>count) | (x<<(32-count)));
    cout<<"\n"<<x;
}

void leftShift(unsigned int x, int count)
{
    x = ((x<<count) | (x>(32-count)));
    cout<<"\n"<<x;
}


void func4(unsigned int x,unsigned int y)
{
    int count=0;
    unsigned int temp = x^y;
    while(temp>0)
    {
        temp &= (temp-1);
        ++count;
    }
    cout<<count;
}

int main()
{
    unsigned int x=32,y=20;
    func4(x,y);
    rightShift(x,2);
    leftShift(x,2);
    return 1;
}