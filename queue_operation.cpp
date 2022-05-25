class MyQueue {
    
    std::stack<int> m_normal;
    std::stack<int> m_reversed;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        m_normal.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if(m_reversed.empty())
        {
            while(!m_normal.empty())
            {
                m_reversed.push(m_normal.top());
                m_normal.pop();
            }
        }
        
        int top = m_reversed.top();
        m_reversed.pop();
            
        return top;
    }
    
    /** Get the front element. */
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
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return m_normal.empty() and m_reversed.empty();
    }
};
