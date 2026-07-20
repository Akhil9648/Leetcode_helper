class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j+1==m){
                        if(i+1==n){
                            mat[0][0]=grid[i][j];
                        }
                        else mat[i+1][0]=grid[i][j];
                    }
                    else mat[i][j+1]=grid[i][j];
                }
            }
            grid=mat;
        }
        return grid;
    }
};