class Solution{
  public:
    bool isInterleave(string a, string b, string c) 
    {
        int n1=a.size(); int n2=b.size(); int n3=c.size();
        int i=0; int j=0;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        if(n1+n2!=n3) return false;
        for(int i=0;i<=n1;++i)
        for(int j=0;j<=n2;++j)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else if(i==0) {
                if(b[j-1]==c[j-1])
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0)
            {
                if(a[i-1]==c[i-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
            else if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(b[j-1]==c[i+j-1] && a[i-1]!=c[i+j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
        return dp[n1][n2];
    }

};