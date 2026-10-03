class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int open=0,close=0;
        int ans=0;
        for(auto  it:s){
            if(it=='('){
                open++;
            }
            else{
                close++;
                if(open<close){
                    open=0;
                    close=0;
                }
            }
            if(open==close){
                int a=open+close;
                ans=max(ans,a);
            }
        }
        open=0,close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                close++;
            }
            else{
                open++;
                if(open>close){
                    open=0;
                    close=0;
                }
            }
            if(open==close){
                int a=open+close;
                ans=max(ans,a);
            }
        }
        return ans;
    }
};