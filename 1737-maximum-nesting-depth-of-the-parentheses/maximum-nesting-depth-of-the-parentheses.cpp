class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<char>st;
        for(auto it:s){
            if(it=='(') st.push(it);
            else if(it==')') st.pop();
            ans=max(ans,(int)st.size());
        }
        return ans;
    }
};