class Solution {
public:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int cnt=0;
        while(!q.empty()){
            auto it=q.front();
            int r=it[0];
            int c=it[1];
            int cost=it[2];
            cnt=max(cnt,cost);
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                 if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc,cost+1});
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};