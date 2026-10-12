class Solution {
public:
    int dr[4]={0,1,-1,0};
    int dc[4]={1,0,0,-1};
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[i][j]){
                dfs(nr,nc,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>pec(n,vector<int>(m,0)),at(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pec);
            dfs(i,m-1,heights,at);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,pec);
            dfs(n-1,j,heights,at);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pec[i][j] && at[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};