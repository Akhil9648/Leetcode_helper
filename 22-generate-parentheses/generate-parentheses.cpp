class Solution {
public:
    void solve(int n,int m,vector<string>& ans,string & curr){
        if(n==0 && m==0){
            ans.push_back(curr);
            return;
        }
        if(n<m){
            curr.push_back(')');
            solve(n,m-1,ans,curr);
            curr.pop_back();
        }
        if(n>0){
            curr.push_back('(');
            solve(n-1,m,ans,curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr;
        solve(n,n,ans,curr);
        return ans;
    }
};