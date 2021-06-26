class Solution{
    public:
    int countMin(string s){
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int p=1;p<n;++p)
        {
            int i=0;
            int j=p;
            while((i)<n &&(j)<n)
            {
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
                ++i;++j;
            }
        }
        return dp[0][n-1];
    }
};