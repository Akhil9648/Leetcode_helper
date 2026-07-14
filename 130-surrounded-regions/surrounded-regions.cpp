class Solution {
public:
    int n,m;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis,vector<vector<int>>& region){
        vis[i][j]=1;
        region.push_back({i,j});
        bool emb=true;
        if(i==0 || i==n-1 || j==0 || j==m-1) emb=false;
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && r<n && c>=0 && c<m){
                if(!vis[r][c] && board[r][c]=='O'){
                    if(!dfs(r,c,board,vis,region)){
                        emb=false;
                    }
                }
            }
        }
        return emb;
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                vector<vector<int>>region;
                if(!vis[i][j] && board[i][j]=='O'){
                if(dfs(i,j,board,vis,region)){
                    for(auto it:region){
                        board[it[0]][it[1]]='X';
                    }
                }
                }
            }
        }
    }
};