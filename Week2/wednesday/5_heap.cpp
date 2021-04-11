#include <bits/stdc++.h>
using namespace std; 
#define DELIM '\n' 
  
void print_last_lines(char *str, int n) 
{ 
    if (n <= 0) 
    return; 
    size_t cnt = 0; 
    char *target_pos = NULL;
    target_pos = strrchr(str, DELIM); 

    if (target_pos == NULL) 
    { 
        cout << "ERROR\n"; 
        return; 
    } 
    while (cnt < n) 
    { 
        while (str < target_pos && *target_pos != DELIM) 
        --target_pos; 
  
        if (*target_pos == DELIM) 
        --target_pos, ++cnt; 
        else
        break; 
    } 
  
    if (str < target_pos) 
    target_pos += 2; 
    cout << target_pos << endl; 
} 

int main(void) 
{ 
    char *str ="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25"; 
    print_last_lines(str, 10); 
    return 0; 
} 