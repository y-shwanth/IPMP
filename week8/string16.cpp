class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        int i = 0;
        while(i<n-1)
        {
            if(s[i] == s[i+1])
            {
                s.erase(i,2);
                if(i != 0 && s[i-1] == s[i])
                {
                    i = i - 1;
                }
                n = s.length();
            }
            else
            {
                ++i;
            }
        }
        return s;
    }
};
