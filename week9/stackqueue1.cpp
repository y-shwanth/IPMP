#include <iostream>
using namespace std;

class twostack {
    int *arr;
    int size;
    int top1,top2;
    
    public:
    twostack(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    void push1(int val)
    {
        ++top1;
        if(top1 != top2)
        arr[top1] = val;
        else
        {
            cout<<"stack is full\n";
            --top1;
        }
    }
    void pop1()
    {
        if(top1 != -1)
        {
            cout<<arr[top1]<<"\n";
            --top1;
        }
    }
    void push2(int val)
    {
        --top2;
        if(top2 != top1)
        arr[top2] = val;
        else
        {
            cout<<"stack is full\n";
            ++top2;
        }
    }
    void pop2()
    {
        if(top2 != size)
        {
            cout<<arr[top2]<<"\n";
            ++top2;
        }
    }
};

int main() {
    twostack t(6);
    t.push1(99);
    t.push2(44);
    t.push2(88);
    t.push2(66);
    t.push2(77);
    t.push1(11);
    t.push2(22);
    
    t.pop2();
    t.pop2();
    t.push1(22);
    t.push1(33);
    t.pop1();
    t.pop1();
    t.pop1();
    return 0;
}
