class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size();
        for(auto it:nums){
            pq.push(it);
        }
        int m=n-k;
        while(m--) pq.pop();
        return pq.top();
    }
};