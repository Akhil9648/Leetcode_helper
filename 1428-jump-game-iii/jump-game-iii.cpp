class Solution {
public:
    int n;
    bool solve(int i,vector<int>& arr,vector<int>&vis){
        if(arr[i]==0) return true;
        if(arr[i]<=i){
            if(!vis[i-arr[i]]){
                vis[i-arr[i]]=1;
                if(solve(i-arr[i],arr,vis)) return true;
            }
        }
        if(arr[i]+i<n){
            if(!vis[i+arr[i]]){
                vis[i+arr[i]]=1;
                if(solve(i+arr[i],arr,vis)) return true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        vector<int>vis(n,0);
        return solve(start,arr,vis);
    }
};