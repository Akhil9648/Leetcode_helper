class Solution {
public:
    int n,m;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int cnt){
        if(grid[i][j]==0) cnt--;
        if(grid[i][j]==2 && cnt==0) return 1;
        if(i>=n || j>=m || i<0 || j<0) return 0; 
        vis[i][j]=1;
        int ans=0;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]!=-1){
                int curr=solve(nr,nc,grid,vis,cnt);
                ans+=curr;
            }
        }
        vis[i][j]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        int sti,stj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) cnt++;
                if(grid[i][j]==1){
                    sti=i;
                    stj=j;
                }
            }
        }
        return solve(sti,stj,grid,vis,cnt);
    }
};