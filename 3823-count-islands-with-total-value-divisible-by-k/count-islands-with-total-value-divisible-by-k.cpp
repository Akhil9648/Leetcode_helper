class Solution {
public:
    int n,m;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int div){
        vis[i][j]=1;
        int sum=0;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>0 && !vis[nr][nc]){
                sum+=(grid[nr][nc]+solve(nr,nc,grid,vis,div));
                sum%=div;
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    int sum=grid[i][j]+solve(i,j,grid,vis,k);
                    sum%=k;
                    if(sum==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};