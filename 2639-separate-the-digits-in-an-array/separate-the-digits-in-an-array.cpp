class Solution {
public:
    void append(string& n,vector<int>& ans){
        for(auto &it:n){
            ans.push_back(it-'0');
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &it:nums){
            string a=to_string(it);
            append(a,ans);
        }
        return ans;
    }
};