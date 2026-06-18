class Solution {
public: 
    int n;
    void solve(vector<int>nums,vector<vector<int>>& ans,vector<int>curr,unordered_set<int>&st){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!st.count(i)){
                curr.push_back(nums[i]);
                st.insert(i);
                solve(nums,ans,curr,st);
                curr.pop_back();
                st.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        n=nums.size();
        vector<int>curr;
        unordered_set<int>st;
        solve(nums,ans,curr,st);
        return ans;
    }
};