class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        long long ans=1LL*(maxi-mini)*k;
        return ans;
    }
};