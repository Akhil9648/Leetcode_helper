class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() && st.top()>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans.empty()?"0":ans;
    }
};