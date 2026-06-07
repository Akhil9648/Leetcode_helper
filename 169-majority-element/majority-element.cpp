class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1,num=nums[0];
        int n=nums.size();
        if(n==1) return num;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) cnt++;
            else cnt=1;
            if(cnt>n/2) num=nums[i];
        }
        return num;
    }
};