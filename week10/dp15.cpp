class Solution {
  public:
    string longestPalin (string s) {
        int n=s.length();
        int mx=1; 
        int start=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) dp[i][i]=1;
            int i=0; int j=1;
            while(i<n && j<n)
            {
                if(s[i]==s[j]) {if(2>mx){start=i; mx=2;} dp[i][j]=1;}
                else dp[i][j]=0;
                ++i;++j;
            }
        
        for(int p=2;p<n;++p)
        {
            i=0; j=p;
            while(i<n && j<n)
            {
                if(s[i]==s[j] && dp[i+1][j-1]) { if(j-i+1>mx){start=i; mx=j-i+1;}dp[i][j]=1;}
                ++i;++j;
            }
        }
        
        return s.substr(start,mx);
    }
};