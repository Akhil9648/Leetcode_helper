class Solution {
public:
    int n;
    int solve(int i,vector<int>& arr,int d,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=1;
        int a=1;
        while(a<=d){
            int j=i-a;
            if(j<0 || arr[j]>=arr[i]) break;
            int curr=1+solve(j,arr,d,dp);
            maxi=max(maxi,curr);
            a++;
        }
        a=1;
        while(a<=d){
            int j=i+a;
            if(j>=n || arr[j]>=arr[i]) break;
            int curr=1+solve(j,arr,d,dp);
            maxi=max(maxi,curr);
            a++;
        }
        return dp[i]=maxi;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            solve(i,arr,d,dp);
        }
        int maxi=0;
        for(auto it:dp){
            maxi=max(maxi,it);
        }
        return maxi;
    }
};