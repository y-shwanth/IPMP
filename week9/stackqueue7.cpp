class Solution {
public:
    int precedence(char op)
    {
        if(op == '+' || op == '-')
            return 1;
        if(op == '*' || op == '/')
            return 2;
        
        return 0;
    }
    
    int func1(int val1, int val2, char op)
    {
        int res;
        switch(op)
        {
            case '+': return val1 + val2;
                break;
            case '-': return val1 - val2;
                break;
            case '*': return val1 * val2;
                break;
            case '/': return val1 / val2;
                break;
        }
        
        return 0;
    }
    
    int calculate(string s) {
        stack<int> vals;
        stack<char> operators;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
                continue;
            else if(s[i] == '(')
                operators.push(s[i]);
            else if(isdigit(s[i]))
            {
                int x = 0;
                while(i<s.length() && isdigit(s[i]))
                {
                    x = x*10 + (s[i] - '0');
                    i++;
                }
                vals.push(x);
                i--;
            }
            else if(s[i] == ')')
            {
                while(!vals.empty() && operators.top() != '(')
                {
                    int val2 = vals.top();
                    vals.pop();
                    int val1 = vals.top();
                    vals.pop();
                    
                    vals.push(func1(val1, val2, operators.top()));
                    operators.pop();
                }
                operators.pop();
            }
            else
            {
                while(!operators.empty() && precedence(operators.top()) >= precedence(s[i]))
                {
                    int val2 = vals.top();
                    vals.pop();
                    int val1 = vals.top();
                    vals.pop();
                    
                    vals.push(func1(val1, val2, operators.top()));
                    operators.pop();
                }
                operators.push(s[i]);
            }
        }
        
        while(!operators.empty())
        {
            int val2 = vals.top();
            vals.pop();
            int val1 = vals.top();
            vals.pop();
            
            vals.push(func1(val1, val2, operators.top()));
            operators.pop();
        }
        
        return vals.top();
    }
};
