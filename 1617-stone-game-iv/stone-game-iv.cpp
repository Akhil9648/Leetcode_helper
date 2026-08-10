class Solution {
public:
    bool solve(int n,vector<int>& dp){
        if(n==0) return dp[n]=false;
        if(dp[n]!=-1) return dp[n];
        for(int k=1;k*k<=n;k++){
            if(!solve(n-k*k,dp)) return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};