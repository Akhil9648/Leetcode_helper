class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=1,num=nums[0];
        vector<int>ans;
        int n=nums.size();
        if(n==1) return {num};
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) cnt++;
            else{
                if(cnt>n/3){
                    ans.push_back(nums[i-1]);
                }
                cnt=1;
            }
        }
        if(cnt>n/3){
             ans.push_back(nums[n-1]);
        }
        return ans;
    }
};