class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int curr=1;
            if(nums[i+1]>nums[i]){
                int j=i+1;
                while(j<n && nums[j]>nums[j-1]){
                    j++;
                    curr++;
                }
                maxi=max(maxi,curr);
            }
            else if(nums[i+1]<nums[i]){
                int j=i+1;
                while(j<n && nums[j]<nums[j-1]){
                    j++;
                    curr++;
                }
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};