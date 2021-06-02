//little more complicated than the normal one
//found in leetcode
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool neg = false;
        string str;
        for(int i=0;i<n;i++)
        {
            if(isalpha(s[i]) || s[i] == '.')
                return 0;
            if(s[i] == ' ')
                continue;
            if(s[i] == '-' && (s[i+1] == '-' || s[i+1] == '+' || s[i+1] == ' '))
                return 0;
            if(s[i] == '+' && (s[i+1] == '+' || s[i+1] == '-' || s[i+1] == ' '))
                return 0;
            if((s[i] == '-' || s[i] == '+') && isdigit(s[i+1]))
            {
                if(s[i] == '-')
                neg = true;
                i++;
                while(isdigit(s[i]))
                {
                    str += s[i];
                    i++;
                }
                break;
            }
            if(isdigit(s[i]))
            {
                while(isdigit(s[i]))
                {
                    str += s[i];
                    i++;
                }
                break;
            }
        }
        cout<<str;
        int nums = 0;
        n = str.length();
        for(int i=0;i<n;i++)
        {
            if(neg)
            {
                if(nums > INT_MAX/10 || (nums == INT_MAX/10 && str[i]-'0' >=8))
                    return INT_MIN;
            }
            else
            {
                if(nums > INT_MAX/10 || (nums == INT_MAX/10 && str[i]-'0' >=7))
                    return INT_MAX;
            }
            nums = nums*10 + (str[i] - '0');
        }
        
        
        if(neg)
            return -1*nums;
        return nums;
    }
};
