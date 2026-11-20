class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int,int>dp;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for (auto &x : nums){
            dp[x+1]=dp[x]+1; 
            dp[x]=dp[x-1]+1;  
            ans=max({ans,dp[x],dp[x+1]});
        }
        return ans;
    }
};
