class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(!pq.empty() && k--){
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};