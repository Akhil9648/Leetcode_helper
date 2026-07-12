class Solution {
public:
    // int n;
    // int solve(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
    //     if(i>=n) return 0;
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     int take=0;
    //     if(prev==-1 || nums[prev]+1==nums[i]){
    //         take=1+solve(i+1,i,nums,dp);
    //     }
    //     int notTake=solve(i+1,prev,nums,dp);
    //     return dp[i][prev+1]=max(take,notTake);
    // }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);
        int curr=1,maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]==nums[i-1]) continue;
            else{
                maxi=max(maxi,curr);
                curr=1;
            }
        }
        maxi=max(maxi,curr);
        return maxi;
    }
};