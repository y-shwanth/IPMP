void func2(int arr[][], int i, int j, int c)
{
    for(int k=j;k<c;k++)
    {
        arr[i][k] = 1;
    }
}

void func1(int arr[][], int r, int c)
{
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             if(arr[i][j] == 1)
             {
                 func2(arr,i,j,c);
                 break;
             }
         }
     }
  
}
