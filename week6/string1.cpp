#include<bits/stdc++.h>
using namespace std;

void printreverse(string s, int i,int n)
{
  if(i == n)
    return;
  printreverse(s,i+1,n);
  cout<<s[i];
}
int main()
{
  string s = "hellohi";
  int n = s.size();
  printreverse(s,0,n);
  return 0;
}
