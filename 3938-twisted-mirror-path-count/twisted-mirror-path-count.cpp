class Solution {
public:
    int n,m;
    int MOD=1e9+7;
    pair<int,int>getNext(int i,int j,int dir,vector<vector<int>>& grid){
        if(i>=m || j>=n) return {-1,-1};
        if(grid[i][j]==0) return {i,j};
        if(dir==0) return getNext(i+1,j,1,grid);
        return getNext(i,j+1,0,grid);
    }
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0;
        auto r=getNext(i,j+1,0,grid);
        if(r.first!=-1){
            a=solve(r.first,r.second,grid,dp);
        }
        auto k=getNext(i+1,j,1,grid);
        if(k.first!=-1){
            b=solve(k.first,k.second,grid,dp);
        }
        return dp[i][j]=(a+b)%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if (grid[0][0] == 1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};