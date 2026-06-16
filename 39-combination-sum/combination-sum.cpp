class Solution {
public:
int n;
    void solve(int i,vector<int>&arr,int target,vector<vector<int>>& ans,vector<int> curr){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(i>=n || target<0) return ;
        solve(i+1,arr,target,ans,curr);
        target-=arr[i];
        curr.push_back(arr[i]);
        solve(i,arr,target,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,candidates,target,ans,curr);
        return ans;
    }
};