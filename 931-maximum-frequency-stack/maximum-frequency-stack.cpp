class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>vals;
    int maxf=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        int f=++freq[val];
        vals[f].push(val);
        if(f>maxf) maxf=f;
    }
    
    int pop() {
        int ans=vals[maxf].top();
        vals[maxf].pop();
        if(vals[maxf].empty()) maxf--;
        freq[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */