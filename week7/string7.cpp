#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void find_rank(string str)
{
    int count = 0;
    string orgstr = str;
    sort(str.begin(),str.end());

    do
    {
        if(str.compare(orgstr) == 0)
        break;
        ++count;
    } while (next_permutation(str.begin(),str.end()));

    cout<<"\n\nrank is "<<count+1<<"\n";
    
}

int main()
{
    string str = "cdabe";
    find_rank(str);
    return 1;
}
