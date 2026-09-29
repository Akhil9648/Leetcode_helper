class Solution {
public:
    int n,m;
    bool solve(int i,int j,vector<vector<char>>& grid,int bal,vector<vector<vector<int>>>&dp){
        if(i>=n || j>=m) return false;
        if(grid[i][j]=='(') bal++;
        else bal--;
        if(bal<0) return false;
        if(i==n-1 && j==m-1){
            return bal==0;
        }
        if(dp[i][j][bal]!=-1) return dp[i][j][bal];
        if(solve(i+1,j,grid,bal,dp)) return dp[i][j][bal]=true;
        if(solve(i,j+1,grid,bal,dp)) return dp[i][j][bal]=true;
        return dp[i][j][bal]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]!='(' || grid[n-1][m-1]!=')') return false;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1000,-1)));
        return solve(0,0,grid,0,dp);
    }
};