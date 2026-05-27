class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string a=it;
            sort(a.begin(),a.end());
            mp[a].push_back(it);
        }
        vector<vector<string>>ans(mp.size());
        int i=0;
        for(auto it:mp){
            for(auto u:it.second){
                ans[i].push_back(u);
            }
            i++;
        }
        return ans;
    }
};