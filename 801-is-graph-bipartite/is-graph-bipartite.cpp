class Solution {
public:
    bool dfs(int i,int col,vector<int>& colour,vector<vector<int>>& graph){
        colour[i]=col;
        for(auto it:graph[i]){
            if(colour[it]==-1){
                if(!dfs(it,!col,colour,graph)) return false;
            }
            if(colour[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(!dfs(i,0,colour,graph)) return false;
            }
        }
        return true;
    }
};