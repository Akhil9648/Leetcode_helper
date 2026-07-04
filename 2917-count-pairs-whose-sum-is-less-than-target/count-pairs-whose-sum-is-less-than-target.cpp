class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<target){
                ans+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};