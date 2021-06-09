class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        map<char,int> m;
        queue<char> q;
        char ch;
        int max = 0;
        int i=0;
        
        while(i<n)
        {
            ++m[s[i]];
            if(m[s[i]] > 1)
            {
                if(q.size() > max)
                    max = q.size();
                ch = q.front();
                --m[ch];
                q.pop();
                --m[s[i]];
            }
            else
            {
                q.push(s[i]);
                ++i;
            }
        }
        if(q.size() > max)
            max = q.size();
        return max;
        
        
        /* 1st TRY
        int max = INT_MIN;
        int i=0,j=0,count=0;
        while(i<n)
        {
            ++m[s[i]];
            if(m[s[i]] > 1)
            {
                if(count > max)
                    max = count;
                m.clear();
                count = 0;
                ++j;
                i = j;
            }
            else
            {
                ++count;
                ++i;
            }
        }
        if(count > max)
            max = count;
        return max;
        */
    }
};
