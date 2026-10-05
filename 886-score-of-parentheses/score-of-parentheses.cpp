class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int sum=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(sum);
                sum=0;
            }
            else{
                if(s[i-1]=='('){
                    sum+=st.top()+1;
                }
                else{
                    sum=2*sum+st.top();
                }
                st.pop();
            }
        }
        return sum;
    }
};