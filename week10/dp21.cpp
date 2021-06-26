class Solution
{
    public:
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;++i) dp[i][1]=1;
        for(int i=1;i<=k;++i) dp[1][i]=i;
        int res;
        for(int i=2;i<=n;++i) 
        for(int j=2;j<=k;++j)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;++x)
            {
                res=1+max(dp[i-1][x-1],dp[i][j-x]);
                dp[i][j]=min(dp[i][j],res);
            }
        }
        return dp[n][k];
    }
};