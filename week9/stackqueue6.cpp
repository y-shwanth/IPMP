class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        
        stack<char> t;
        for(int i=0;i<n;i++)
        {
            if(!t.empty() && t.top() == '(' && s[i] == ')')
                t.pop();
            else if(!t.empty() && t.top() == '{' && s[i] == '}')
                t.pop();
            else  if(!t.empty() && t.top() == '[' && s[i] == ']')
                t.pop();
            else
            t.push(s[i]);
        }
        
        if(t.size() == 2)
        {
            char ch = t.top();
            t.pop();
            
            if(!t.empty() && t.top() == '(' && ch == ')')
                t.pop();
            if(!t.empty() && t.top() == '{' && ch == '}')
                t.pop();
            if(!t.empty() && t.top() == '[' && ch == ']')
                t.pop();
        }
        
        if(t.empty())
            return true;
        
        return false;
    }
};
