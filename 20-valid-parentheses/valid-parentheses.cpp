class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(char c:s){
            if(c==')' && !st.empty() && st.top()=='(') st.pop();
            else if(c==']' && !st.empty() && st.top()=='[') st.pop();
            else if(c=='}' && !st.empty() && st.top()=='{') st.pop();
            else st.push(c);
        }
        return st.size()==0;
    }
};