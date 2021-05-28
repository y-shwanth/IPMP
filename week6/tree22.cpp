#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;


void kthnodeinNthlevel(int k,int n)
{
    double result = pow((double)n,2);
    int a = (int) result;
    if(k > a)
    {
        cout<<"INVALID";
        return;
    }
    if(n == 1)
    {
        cout<<"Kth node in Nth level : 0\n";
        return;
    }
    int x;
    queue<int> oldq,newq;
    oldq.push(0);
    for(int i=1;i<n;i++)
    {
        while(oldq.empty() == false)
        {
            x = oldq.front();
            oldq.pop();
            if(x == 0)
            {
                newq.push(0);
                newq.push(1);
            }
            else
            {
                newq.push(1);
                newq.push(0);
            }
        }
        oldq = newq;
        newq = queue<int>();
    }
    for(int i=0;i<k-1;i++)
    {
        oldq.pop();
    }
    cout<<"Kth node in Nth level : "<<oldq.front()<<"\n";
}

int main()
{
    kthnodeinNthlevel(5,5);
    kthnodeinNthlevel(6,5);
    kthnodeinNthlevel(7,5);
    kthnodeinNthlevel(8,5);
    return 0;
}
