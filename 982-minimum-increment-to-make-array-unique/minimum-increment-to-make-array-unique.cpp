class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1] || nums[i]<nums[i-1]){
                int a=nums[i-1]-nums[i]+1;
                nums[i]+=a;
                cnt+=a;
            }
        }
        return cnt;
    }
};