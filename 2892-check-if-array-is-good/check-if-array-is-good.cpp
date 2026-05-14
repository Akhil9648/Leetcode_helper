class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]!=i+1) return false;
        }
        if(n>1 && nums[n-1]==nums[n-2]) return true;
        return false;
    }
};