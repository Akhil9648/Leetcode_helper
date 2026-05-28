class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        vector<vector<int>>arr;
        for(auto it:mp){
            arr.push_back({it.first,it.second});
        }
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<k;i++){
            ans.push_back(arr[n-i-1][0]);
        }
        return ans;
    }   
};