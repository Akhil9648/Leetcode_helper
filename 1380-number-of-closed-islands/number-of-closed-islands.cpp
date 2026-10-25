class Solution {
public:
    int n,m;
    int dr[4]={0,1,-1,0};
    int dc[4]={1,0,0,-1};
    void solve(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0) solve(nr,nc,grid);
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || j==m-1 || i==0 || j==0) && grid[i][j]==0){
                    solve(i,j,grid);
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    solve(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};