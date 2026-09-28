class Solution {
public:
    int solve(int ops,int l,vector<int>& nums,vector<int>& mul,int m,vector<vector<int>>& dp,int n){
        if(ops>=m) return 0;
         int r=n-1-(ops-l);
        if(dp[l][ops]!=-1) return dp[l][ops];
        int st=mul[ops]*nums[l]+solve(ops+1,l+1,nums,mul,m,dp,n);
        int end=mul[ops]*nums[r]+solve(ops+1,l,nums,mul,m,dp,n);
        return dp[l][ops]=max(st,end);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers){
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,0,nums,multipliers,m,dp,n);
    }
};