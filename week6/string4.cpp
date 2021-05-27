class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string str = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                if(str.length() != 0)
                    v.push_back(str);
                str = "";
            }
            else
            {
                str = str + s[i];
            }
        }
        if(str.length() != 0)
            v.push_back(str);
        
        int n = v.size();
        str = v[n-1];
        for(int i=v.size() -2;i>=0;i--)
        {
            str = str + " " + v[i];
        }
        return str;
    }
};
