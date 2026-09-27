class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string res="";
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:res){
                    st.push(it);
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};