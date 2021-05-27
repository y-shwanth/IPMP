class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++)
            ++freq[s[i]];
        unordered_map<char, int> state;
        vector<char> stac;
        
        for(int i=0;i<s.length();i++)
        {
            --freq[s[i]];
            if(state[s[i]] == 1)
                continue;
            while(stac.empty() == false && stac[stac.size() - 1] > s[i] && freq[stac[stac.size() -1]] > 0)
            {
                state[stac[stac.size() - 1]] = 0;
                stac.pop_back();
            }
            
            stac.push_back(s[i]);
            state[s[i]] = 1;    
        }
        string str = "";
        for(int i=0;i<stac.size();i++)
            str = str + stac[i];
        
        return str;
    }
};
