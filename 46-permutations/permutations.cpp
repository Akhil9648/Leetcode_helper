class Solution {
public: 
    int n;
    void solve(vector<int>&nums,vector<vector<int>>& ans,vector<int>curr){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(nums[i]<11){
                curr.push_back(nums[i]);
                int a=nums[i];
                nums[i]=11;
                solve(nums,ans,curr);
                curr.pop_back();
                nums[i]=a;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        n=nums.size();
        vector<int>curr;
        solve(nums,ans,curr);
        return ans;
    }
};