//similar to the one in pdf
//found in leetcode
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        char ch = chars[0];
        string str;
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(ch != chars[i])
            {
                str += ch;
                if(count != 1)
                str.append(to_string(count));
                ch = chars[i];
                count = 1;
                continue;
            }
            ++count;
            
        }
        str += ch;
        if(count != 1)
        str.append(to_string(count));
        
        chars.clear();
        for(int i=0;i<str.length();i++)
        {
            chars.push_back(str[i]);
        }
        
        return chars.size();
    }
};
