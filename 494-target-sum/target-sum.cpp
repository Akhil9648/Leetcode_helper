class Solution {
public:
    int n;
    int k;
    int solve(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(i>=n){
            if(target==0) return 1;
            return 0;
        }
        if(abs(target)>k) return 0;
        if(dp[i][target+k]!=-1) return dp[i][target+k];
        int plus=solve(i+1,nums,target+nums[i],dp);
        int minus=solve(i+1,nums,target-nums[i],dp);
        return dp[i][target+k]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        k = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target)>k) return 0;
        vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        return solve(0,nums,target,dp);
    }
};