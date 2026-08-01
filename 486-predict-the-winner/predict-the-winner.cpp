class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int b=nums[j]+min(solve(i,j-2,nums,dp),solve(i+1,j-1,nums,dp));
        return dp[i][j]=max(a,b); 
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums) sum+=it;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int a=solve(0,n-1,nums,dp);
        int b=sum-a;
        return a>=b;
    }
};