class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int sum=nums[i]+nums[j];
                if(sum<target){
                    ans+=(j+1);
                    break;
                }
            }
        }
        return ans;
    }
};