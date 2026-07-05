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