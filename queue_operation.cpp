#include<bits/stdc++.h>
using namespace std;
class MyQueue {   
stack<int> m_normal;
stack<int> m_reversed;
public:
        void push(int x) {
        
            m_normal.push(x);
        }
        int pop() {
        if( m_normal.empty() and m_reversed.empty())
        {
            cout<<"empty"<<endl;
        }
        else
        {
        if(m_reversed.empty())
        {
            while(!m_normal.empty())
            {
                m_reversed.push(m_normal.top());
                m_normal.pop();
            }
        }
        }
        int top = m_reversed.top();
        m_reversed.pop();
            
        return top;
    }
    int peek() {
        if(m_reversed.empty())
        {
            while(!m_normal.empty())
            {
                m_reversed.push(m_normal.top());
                m_normal.pop();
            }
        }
        return m_reversed.top();
    }
    bool empty() {
        
        return m_normal.empty() and m_reversed.empty();
    }
};
int main()
{
    MyQueue ob = MyQueue();
    ob.push(45);
    ob.push(78);
    ob.push(78);
    ob.push(45);
    ob.push(89);
    ob.pop();
    ob.pop();
    ob.pop();
    ob.pop();
    cout<<ob.peek();
    return 0;
}
