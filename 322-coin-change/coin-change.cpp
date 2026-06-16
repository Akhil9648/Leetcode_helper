class Solution {
public:
    int n;
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(amt==0) return 0;
        if(amt<0) return 1e8;
        if(i>=n) return 1e8;
        if(dp[i][amt]!=-1) return dp[i][amt]; 
        int notTake=solve(i+1,amt,coins,dp);
        int take=1+solve(i,amt-coins[i],coins,dp);
        return dp[i][amt]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int a=solve(0,amount,coins,dp);
        return a>=1e8?-1:a;
    }
};