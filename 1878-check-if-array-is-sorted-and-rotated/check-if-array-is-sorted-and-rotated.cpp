class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                cnt=i;
                break;
            }
        }
        rotate(nums.begin(),nums.begin()+cnt,nums.end());
        return is_sorted(nums.begin(),nums.end());
    }
};