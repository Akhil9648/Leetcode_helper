class MinStack {
public:
    stack<int>st;
    priority_queue<int,vector<int>,greater<int>>pq;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        pq.push(value);
    }
    
    void pop() {
        int a=st.top();
        st.pop();
        priority_queue<int>buff;
        while(!pq.empty() && (pq.top()!=a)){
            buff.push(pq.top());
            pq.pop();
        }
        pq.pop();
        while(!buff.empty()){
            pq.push(buff.top());
            buff.pop();
        }
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return -1;
    }
    
    int getMin() {
        if(!pq.empty()) return pq.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */