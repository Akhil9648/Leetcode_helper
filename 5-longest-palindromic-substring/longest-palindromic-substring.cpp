class Solution {
public:
    string ans;
    bool isPal(int start,int end,string &s){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int solve(int st,int end,string &s,vector<vector<int>>& dp){
        if(st>end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        if(s[st]==s[end] && isPal(st,end,s)){
            int size=end-st+1;
            if(size>ans.size()) ans=s.substr(st,size);
        }
        int take=solve(st+1,end,s,dp);
        int notTake=solve(st,end-1,s,dp);
        return dp[st][end]=max(take,notTake);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(0,n-1,s,dp);
        return ans;
    }
};