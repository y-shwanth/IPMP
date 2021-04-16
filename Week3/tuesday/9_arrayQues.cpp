#include<bits/stdc++.h>
using namespace std;

vector<int> square(int n)
{
    vector<int> sq;
    for(int i=1;i<=n;i++)
    {
        sq.push_back(pow(i,2));
    }
    return sq;
}

void findtriplet(int c)
{
    vector<int> sq = square(c);
    int asq,bsq,j,a,b,count=0;
    for(int i=1;i<c;i++)
    {
        asq = pow(i,2);
        for(j=1;j<sq.size();j++)
        {
            bsq = abs(sq[j] - asq);
            b = sqrt(bsq);
            a = sqrt(asq);
            if(c<a || find(sq.begin(),sq.end(),bsq) == sq.end())
            continue;
            if(b>=a && c>=b && (asq + bsq == sq[j]))
            ++count;
        }
    }
    cout<<"count "<<count;
    return;
}

int main()
{
    findtriplet(10);
    return 1;
}