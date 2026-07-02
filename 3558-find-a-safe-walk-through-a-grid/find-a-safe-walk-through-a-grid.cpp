class Solution {
public:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int n,m;
    bool solve(int i,int j,vector<vector<int>>& grid,int health,vector<vector<int>>& vis,vector<vector<vector<int>>>& dp){
        if(i>=n || j>=m || health<=0) return false;
        if(i==n-1 && j==m-1) return true;
        if(dp[i][j][health]!=-1) return dp[i][j][health];
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                if(grid[nr][nc]==1){
                    if(solve(nr,nc,grid,health-1,vis,dp)) return dp[i][j][health]=true;
                }
                else{
                    if(solve(nr,nc,grid,health,vis,dp)) return dp[i][j][health]=true;
                }
            }
        }
        vis[i][j]=0;
        return dp[i][j][health]=false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0]) health--;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(health+1,-1)));
        return solve(0,0,grid,health,vis,dp);
    }
};