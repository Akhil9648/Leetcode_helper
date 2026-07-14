class Solution {
public:
    int n;
    int solve(int low,int high,vector<int>& nums){
        if(low>high) return 0;
        int mid=(low+high)/2;
        if(mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
        if(mid==0 && mid<n-1 && nums[mid]>nums[mid+1]) return mid;
        if(mid==n-1 && mid>0 && nums[mid]>nums[mid-1]) return mid;
        int a=solve(low,mid-1,nums);
        int b=solve(mid+1,high,nums);
        if(a>0) return a;
        if(b>0) return b;
        return 0;
    }
    int findPeakElement(vector<int>& nums) {
        n=nums.size();
        return solve(0,n-1,nums);
    }
};