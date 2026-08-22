class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0,cnt=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};