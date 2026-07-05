class Solution1 {
public:
    int n;
    int solve(int i,vector<int>& nums,int k,vector<vector<int>>& dp){
        if(k==0){
            return (i>=n)?0:1e9;
        }
        if(i>=n) return 1e9;
        if(dp[i][k]!=-1) return dp[i][k];
        int curr=0;
        int maxi=1e9;
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
class Solution {
public:
    bool solve(int mid,vector<int>& nums,int k){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]>mid){
                sum=nums[i];
                k--;
            }
            else sum+=nums[i];
        }
        return k-1>=0;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(auto it:nums){
            high+=it;
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};