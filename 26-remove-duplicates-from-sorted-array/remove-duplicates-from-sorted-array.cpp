class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]=-101;
                count++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-101){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return n-count;
    }
};