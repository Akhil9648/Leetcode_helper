class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        int cnt=0;
        while(i<j){
            int a=nums[i]+nums[j];
            if(a<target){
                cnt+=(j-i);
                cout<<nums[i]<<" ";
                i++;
            }
            else j--;
        }
        return cnt;
    }
};