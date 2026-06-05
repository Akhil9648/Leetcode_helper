class Solution {
public:
    int dr[4]={0,1,-1,0};
    int dc[4]={1,0,0,-1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]) cnt++;
                    }
                    peri+=(4-cnt);
                }
            }
        }
        return peri; 
    }
};