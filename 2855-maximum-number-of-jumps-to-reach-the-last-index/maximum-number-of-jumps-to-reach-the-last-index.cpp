class Solution {
public:
    int n;
    int solve(int i,vector<int>&nums,int target,vector<int>& dp){
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-2) return dp[i];
        int take=-1;
        int u=i+1;
        for(;u<n;u++){
            int curr=nums[u]-nums[i];
            if(curr>=-1*target && curr<=target){
                int a=solve(u,nums,target,dp);
                if(a!=-1) take=max(take,a+1);
            }
        }
        return dp[i]=take;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        vector<int>dp(n,-2);
        int a=solve(0,nums,target,dp);
        return a;
    }
};