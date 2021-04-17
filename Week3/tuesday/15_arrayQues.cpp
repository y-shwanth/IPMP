#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

void findrow(int mat[R][C])
{
    int maxrow = 0;
    int leftmost,i,j;
    for(j=0;j<C;j++)
    {
        if(mat[0][j] == 1)
        {
            leftmost = j;
            break;
        }
    }

    for(i=1;i<R;i++)
    {
        if(mat[i][leftmost - 1] == 1)
        {
            maxrow = i;
            for(j = leftmost-1;j>=0;j--)
            {
                if(mat[i][j] == 1)
                leftmost = j;
                else
                break;
            }
            if(leftmost == 0)
            break;
        }
    }
    cout<<maxrow<<"\n";
}

int main()
{
    int mat[R][C] = {
        {0,0,1,1,1},
        {0,0,0,0,1},
        {0,0,0,1,1},
        {0,1,1,1,1}
    };
    findrow(mat);
    return 1;
}