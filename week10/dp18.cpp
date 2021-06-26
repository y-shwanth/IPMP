class Solution {
  public:
    long long noOfWays(int m , int n , int x) {
        vector<vector<long long>> dp(n+1,vector<long long> (x+1,0));
        for(long long i=1;i<=x && i<=m;++i) dp[1][i]=1;
        
        for(long long i=2;i<=n;++i)
        for(long long j=1;j<=x;++j)
        for(long long k=1;k<=m && k<=j;++k)
        dp[i][j]+=dp[i-1][j-k];
        return dp[n][x];
    }
};