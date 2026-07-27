class Solution1 {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                for(int k=0;k<=limit;k++){
                    if(i+j+k==n) cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution2 {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                int a=n-(i+j);
                if(a<=limit && a>=0) cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int solve(int n,int limit,int child,vector<vector<int>>& dp){
        if(n==0 && child==0) return 1;
        if(child==0) return 0;
        if(dp[n][child]!=-1) return dp[n][child];
        int ans=0;
        for(int i=0;i<=limit;i++){
            if(n>=i) ans+=solve(n-i,limit,child-1,dp);
        }
        return dp[n][child]=ans;
    }
    int distributeCandies(int n, int limit) {
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(n,limit,3,dp);
    }
};