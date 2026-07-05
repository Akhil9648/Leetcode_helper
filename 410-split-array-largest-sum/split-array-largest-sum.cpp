class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums,int k,vector<vector<int>>& dp){
        if(k==0){
            return (i>=n)?0:1e9;
        }
        if(i>=n) return 1e9;
        if(dp[i][k]!=-1) return dp[i][k];
        int maxi=1e9;
        int curr=0;
        for(int j=i;j<=n-k;j++){
            curr+=nums[j];
            int remain=solve(j+1,nums,k-1,dp);
            int mini=max(curr,remain);
            maxi=min(maxi,mini);
        }
        return dp[i][k]=maxi;
    }
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,nums,k,dp);
    }
};