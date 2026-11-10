class Solution1 {
public:
    int solve(int i,vector<int>&costs,vector<int>& dp){
        if(i<-1) return 1e9;
        if(i==-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int t1=solve(i-1,costs,dp)+1;
        int t2=solve(i-2,costs,dp)+4;
        int t3=solve(i-3,costs,dp)+9;
        return dp[i]=min({t1,t2,t3})+costs[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n,-1);
        return solve(n-1,costs,dp);
    }
};
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a=1e9,b=1e9,c=0;
        for(int i=0;i<n;i++){
            int c1=c+1;
            int c2=b+4;
            int c3=a+9;
            int curr=min({c1,c2,c3})+costs[i];
            a=b;
            b=c;
            c=curr;
        }
        return c;
    }
};