class Solution {
public:
    int minMoves(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i:nums){
            ans+=(a-i);
        }
        return ans;
    }
};