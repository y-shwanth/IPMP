#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <deque>
using namespace std;

class middlestack {
    stack<int> first;
    deque<int> second;
    public:
    middlestack()
    {
    }
    void pushh(int val)
    {
        if(first.empty())
        {
            first.push(val);
            return;
        }
        if(first.size() > second.size())
        second.push_back(val);
        else
        {
            first.push(second.front());
            second.pop_front();
            second.push_back(val);
        }
    }
    void popp()
    {
        if(second.empty())
        {
            first.pop();
            return;
        }
        if(first.size() == second.size())
        {
            second.pop_back();
        }
        else
        {
            second.push_front(first.top());
            first.pop();
            second.pop_back();
        }
    }
    int get_top()
    {
        return second.back();
    }
    int get_middle()
    {
        return first.top();
    }
    void delete_middle()
    {
        if(first.size() > second.size())
        first.pop();
        
        else
        {
            first.pop();
            first.push(second.front());
            second.pop_front();
        }
    }
};

int main() {
    
    middlestack m;
    m.pushh(1);
    m.pushh(2);m.pushh(3);m.pushh(4);m.pushh(5);m.pushh(6);m.pushh(7);
    
    cout<<m.get_middle()<<"\n";
    m.delete_middle();
    cout<<m.get_middle()<<"\n";
    
    cout<<m.get_top()<<"\n";
    m.popp();
    m.popp();
    cout<<m.get_top()<<"\n";
    cout<<m.get_middle()<<"\n";
    return 0;
}
