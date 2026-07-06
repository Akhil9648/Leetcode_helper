class Solution {
public:
    bool check(int i,int j,vector<string>& curr,int n){
        for(int k=0;k<n;k++){
            if(curr[i][k]=='Q') return false;
        }
        int u=i,v=j;
        while(u>=0 && v>=0){
            if(curr[u][v]=='Q') return false;
            u--;
            v--;
        }
        u=i,v=j;
        while(u<n && v>=0){
            if(curr[u][v]=='Q') return false;
            u++;
            v--;
        }
        return true;
    }
    void solve(int j,int n,vector<string>& curr,vector<vector<string>>& ans){
        if(j>=n){
            ans.push_back(curr);
        }
        for(int i=0;i<n;i++){
            if(check(i,j,curr,n)){
                curr[i][j]='Q';
                solve(j+1,n,curr,ans);
                curr[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>curr;
        string s(n,'.');
        for(int i=0;i<n;i++){
            curr.push_back(s);
        }
        solve(0,n,curr,ans);
        return ans;
    }
};