#include <bits/stdc++.h>
#define NO_OF_CHAR 256
using namespace std;
 
int* getcountarray(string str2)
{
    int* count = (int*)calloc(sizeof(int), NO_OF_CHAR);
 
    for (int i = 0; i < str2.size(); i++)
    {
        count[str2[i]]++;
    }
 
    return count;
}
 
string removeDirtyChars(string str1, string str2)
{
    int* count = getcountarray(str2);
    string res;
    int ip_idx = 0;
 
    while (ip_idx < str1.size())
    {
        char temp = str1[ip_idx];
        if (count[temp] == 0)
        {
            res.push_back(temp);
        }
        ip_idx++;
    }
 
    return res;
}

int main()
{
    string str1 = "yeshwanth";
    string str2 = "hey";
    cout << removeDirtyChars(str1, str2) << endl;
    return 1;
}
