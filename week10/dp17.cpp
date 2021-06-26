class Solution{
public:
    int palindromicPartition(string s)
    {
        int n=s.length();
        vector<vector<int>> p(n,vector<int>(n,0));
        vector<vector<int>> c(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            p[i][i]=1; c[i][i]=0;
        }
        for(int x=1;x<n;++x)
        {
            int i=0;
            int j=x;
            while(i<n && j<n)
            {
                if(i+1==j){
                    if(s[i]==s[j]) p[i][j]=1; else p[i][j]=0;
                }
                else{
                    if(s[i]==s[j] && p[i+1][j-1]) p[i][j]=1;
                    else p[i][j]=0;
                }
                if(p[i][j]) c[i][j]=0;
                else {
                    c[i][j]=INT_MAX;
                    for(int k=i;k<j;++k)
                    {
                        c[i][j]=min(c[i][j],c[i][k]+c[k+1][j]+1);
                    }
                }
                ++i;++j;
            }
        }
       
        return c[0][n-1];
        
    }
};