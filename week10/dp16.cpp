class Solution {
public:
    int l(string s,int a, int b)
    {
        if(a>b) return 0;
        if(a==b) return 1;
        if(s[a]==s[b]) return l(s,a+1,b-1)+2;
        return max(l(s,a+1,b),l(s,a,b-1));
    }
    int longestPalindromeSubseq(string s) {
        int mx=1;
        int n=s.length();
        return l(s,0,n-1);
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) dp[i][i]=1;
        int i=0; int j=1;
        while(i<n && j<n)
        {
            if(s[i]==s[j]) {dp[i][j]=2;}
            else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            ++i;++j;
        }
        for(int p=2;p<n;++p)
        {
            i=0; j=p;
            while(i<n && j<n)
            {
                if(s[i]==s[j]){ dp[i][j]=dp[i+1][j-1]+2;}
                else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                ++i;++j;
            }
        }
        
        return max(dp[0][n-1],1);
    }
};