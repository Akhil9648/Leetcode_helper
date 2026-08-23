class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        vector<int>ans;
        int j=0;
        for(int i=0;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if((i-k+1)>=0){
                ans.push_back(nums[dq.front()]);
                if(nums[dq.front()]==nums[j]){
                    dq.pop_front();
                    cout<<nums[j]<<" "<<i<<" ";
                }
                j++;
            }
        }
        return ans;
    }
};