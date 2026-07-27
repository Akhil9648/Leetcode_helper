class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,i+nums[i]);
            if(maxi>=n-1) return true;
            if(maxi<=i) return false;
        }
        return maxi>=n-1;
    }
};