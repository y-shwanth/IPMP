//both attempts passed 265/266 testcases
class Solution {
public:
    /* 1st TRY
    bool is_present(vector<char>& v, string t)
    {
        int len = v.size();
        for(int i=0;i<len;i++)
        {
            if(t.find(v[i]) < len)
                t.erase(t.find(v[i]),1);
        }
        if(t.empty() == true)
            return true;
        
        return false;
    }
    */
    
    bool just_see(map<char,int>&m, map<char,int>&xmap, string t, int w)
    {
        for(int i=0;i<w;i++)
        {
            if(m[t[i]] > xmap[t[i]])
                return false;
        }
        return true;
    }
    
    string get_str(vector<char>&v)
    {
        string str = "";
        for(int i=0;i<v.size();i++)
        {
            str = str + v[i];
        }
        return str;
    }
    
    bool comparing(string s, string t)
    {
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(t.find(s[i]) < n)
                t.erase(t.find(s[i]),1);
        }
        if(t.empty() == true)
            return true;
        
        return false;
    }
    
    string minWindow(string s, string t) {
        int n = s.length();
        int w = t.length();
        
        if(n < w)
            return "";
        if(n == w)
        {
            if(comparing(s,t))
                return s;
            else
                return "";
        }
        
        map<char,int> m,xmap;
        for(int i=0;i<w;i++)
            ++m[t[i]];
        
        bool set = true;
        vector<char> q,res;
        int i=0;
        int min = INT_MAX;
        while(i<n)
        {   
            while(just_see(m,xmap,t,w) && q.size() >= w)
            {
                if(q.size() <= min)
                {
                    min = q.size();
                    res.clear();
                    res = q;
                }
                --xmap[q[0]];
                q.erase(q.begin());
            }
            
            ++xmap[s[i]];
            q.push_back(s[i]);
            ++i;
            
            if(min == w)
                break;
        }
        
        while(just_see(m,xmap,t,w) && q.size() >= w)
        {
            if(q.size() <= min)
            {
                min = q.size();
                res.clear();
                res = q;
            }
            --xmap[q[0]];
            q.erase(q.begin());
        }
        
        string str = get_str(res);
        return str;
    }
};
