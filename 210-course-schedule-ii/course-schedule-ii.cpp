class Solution {
public:
    bool solve(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans,vector<int>& path){
        vis[i]=1;
        path[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(solve(it,adj,vis,ans,path)) return true;
            }
            if(path[it]){
                return true;
            }
        }
        path[i]=0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses,0),ans,pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(solve(i,adj,vis,ans,pathvis)) return {};
            }
        }
        return ans;
    }
};