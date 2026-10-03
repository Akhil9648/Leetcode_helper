class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        vector<int>ans;
        for(auto it:vec){
            int a=it.second;
            while(a--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};