class MinStack {
public:
    stack<long long int> s;
    long long int min;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        long long int val1 = val;
        if(s.empty())
        {
            min = val;
            s.push(val);
            return;
        }
        if(val < min)
        {
            s.push((2*val1) - min);
            min = val;
            return;
        }
        s.push(val);
    }
    
    void pop() {
        if(s.top() >= min)
            s.pop();
        else
        {
            min = 2*min - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top() >= min)
            return s.top();
        
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
