class Solution {
public:
    int n,m;
    int solve(int i,int j,string &word1,string &word2,vector<vector<int>>& dp){
        if(i==n && j==m) return 0;
        if(i==n || j==m){
            return n-i+m-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }
        return dp[i][j]=1+min({
            solve(i+1,j,word1,word2,dp),
            solve(i,j+1,word1,word2,dp),
            solve(i+1,j+1,word1,word2,dp)
        });
    }
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};