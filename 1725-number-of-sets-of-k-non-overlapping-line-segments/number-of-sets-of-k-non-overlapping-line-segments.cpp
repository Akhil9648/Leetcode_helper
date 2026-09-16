class Solution {
public:
    int MOD=1e9+7;
    int numberOfSets(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int u=1;u<=k;u++){
            vector<int>prev(n+1,0);
            for(int i=n-1;i>=0;i--){
                prev[i]=(prev[i+1]+dp[i][u-1])%MOD;
            }
            for(int i=n-1;i>=0;i--){
                int skip=dp[i+1][u];
                int take=prev[i+1];
                dp[i][u]=(take+skip)%MOD;
            }
        }
        return dp[0][k];
    }
};