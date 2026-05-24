class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int j=n-1,i=0;
        while(j>0 && nums[j]==0) j--;
        int cnt=0;
        while(i<j){
            if(nums[i]==0){
                cnt++;
                j--;
            }
            while(j>0 && nums[j]==0) j--;
            i++;
        }
        return cnt;
    }
};