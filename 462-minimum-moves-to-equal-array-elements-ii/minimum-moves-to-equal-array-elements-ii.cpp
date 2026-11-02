class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[n/2];
        if(n%2==0){
            a=(nums[n/2-1]+nums[n/2])/2;
        }
        int ans=0;
        for(auto &it:nums){
            ans+=abs(a-it);
        }
        return ans;
    }
};