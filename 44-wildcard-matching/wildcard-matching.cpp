class Solution {
public:
    int n,m;
    bool solve(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if(i>=n && j>=m) return true;
        if(j>=m) return false;
        if(i>=n){
            while(j<m && p[j] == '*'){
                j++;
            }
            return j == p.size();
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            if(solve(i+1,j+1,s,p,dp)) return dp[i][j]=true;
        }
        if(p[j]=='*'){
            if(solve(i+1,j,s,p,dp)) return dp[i][j]=true;
            if(solve(i,j+1,s,p,dp)) return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s,p,dp);
    }
};