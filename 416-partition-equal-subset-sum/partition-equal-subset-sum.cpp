class Solution {
public:
    int n;
    bool solve(int i,vector<int>& nums,int curr,int &sum,vector<vector<int>>& dp){
        if(curr*2==sum) return true;
        if(i>=n){
            return false;
        }
        if(dp[i][curr]!=-1) return dp[i][curr];
        bool take=solve(i+1,nums,curr+nums[i],sum,dp);
        if(take) return dp[i][curr]=true;
        bool notTake=solve(i+1,nums,curr,sum,dp);
        return dp[i][curr]=notTake;
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(auto &it:nums) sum+=it;
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return solve(0,nums,0,sum,dp);
    }
};