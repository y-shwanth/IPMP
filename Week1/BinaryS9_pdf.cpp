#include<bits/stdc++.h>
using namespace std;

int main()
{
    int narr[] = {1,7,8,10};
    int mnarr[] = {-1,4,-1,9,11,-1,-1,12};
    int n=4,mn=8;
    int i,j=mn-1;
    for(i=mn-1;i>0;i--)
    {
        if(mnarr[i]!=-1)
        {
            mnarr[j] = mnarr[i];
            --j;
        }
        
    }
    int k=0;i=n;j=0;
    while(k < mn)
    {
        if((j==n) || (i<mn) && narr[j]>mnarr[i])
        {
           mnarr[k]=mnarr[i];
            ++i;k++; 
        }
        else
        {
            mnarr[k]=narr[j];
            ++j;k++;
        }
    }
    cout<<"FINAL ARRAY\n";
    for(i=0;i<mn;i++)
    cout<<mnarr[i]<<" ";
    return 1;
}