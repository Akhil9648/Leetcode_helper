class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int curr=1,maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]==nums[i-1]) continue;
            else{
                maxi=max(maxi,curr);
                curr=1;
            }
        }
        maxi=max(maxi,curr);
        return maxi;
    }
};