class Solution1 {
public:
    int solve(int i,int j,vector<int>& nums,int x){
        int front=1e9,rear=1e9;
        if(x==0) return 0;
        if(i>j) return 1e9;
        if(nums[i]<=x){
            front=1+solve(i+1,j,nums,x-nums[i]);
        }
        if(nums[j]<=x){
            rear=1+solve(i,j-1,nums,x-nums[j]);
        }
        return min(front,rear);
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();     
        int ans=solve(0,n-1,nums,x);
        return ans>=1e9?-1:ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0,maxi=-1;
        for(auto &it:nums) sum+=it;
        int left=0;
        int target=sum-x;
        if(target<0) return -1;
        if(target==0) return n;
        sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>target && left<=r){
                sum-=nums[left];
                left++;
            }
            if(sum==target) maxi=max(maxi,r-left+1);
        }
        return maxi==-1?-1:n-maxi;
    }
};