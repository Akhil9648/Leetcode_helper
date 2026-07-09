class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string a=it;
            sort(a.begin(),a.end());
            mp[a].push_back(it);
        }
        vector<vector<string>>ans;
        int i=0;
        for(auto it:mp){
           ans.push_back(it.second);
        }
        return ans;
    }
};