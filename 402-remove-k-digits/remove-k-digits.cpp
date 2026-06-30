class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto it:num){
            while(k>0 && !st.empty() && st.top()>it){
                k--;
                st.pop();
            }
            st.push(it);
        }
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        string ans;
        while(!st.empty()){
            char c=st.top();
            ans+=c;
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans.empty()?"0":ans;
    }
};