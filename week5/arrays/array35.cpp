
void func1(int arr[][], int r, int c)
{
    set<int> cur_col,old_col,col,row;
    set<int>::iterator it,itr;
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             if(arr[i][j] == 0)
             {
                 cur_col.insert(j);
             }
         }
         if(cur_col.size() == r)
             row.insert(i);
         it = set_intersection(cur_col.begin(), cur_col.end(), old_col.begin(), old_col.end(), col.begin());
         old_col = col;
         col.clear();
         cur_col.clear();
     }
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             arr[i][j] = 1;
         }
     }
     for(it = row.begin();it != row.end();it++)
     {
         for(itr = old_col.begin();itr != old_col.end();itr++)
         {
             arr[*it][*itr] = 0;
         }
     }
     return 0;
}
