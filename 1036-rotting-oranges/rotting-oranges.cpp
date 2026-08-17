class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int dr[6]={0,1,0,-1};
        int dc[6]={1,0,-1,0};
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty()){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m  && vis[nr][nc]==0 && grid[nr][nc]==1){
                    vis[nr][nc]=vis[r][c]+1;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
                ans=max(ans,vis[i][j]);
            }
        }
        return ans;
    }
};