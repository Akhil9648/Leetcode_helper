class Solution {
public:
    int n;
    void solve(int i,vector<int>&nums,int target,vector<vector<int>>& ans,vector<int>& curr){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(i>=n || target<0) return ;
        for(int j=i;j<n;j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            curr.push_back(nums[j]);
            solve(j+1,nums,target-nums[j],ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         n=candidates.size();
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans,curr);
        return ans;
    }
};