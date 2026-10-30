class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       vector<vector<pair<int,int>>>adj(n);
       for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
       } 
       vector<vector<int>>dist(n,vector<int>(k+1,1e9));
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       dist[0][1]=0;
       pq.push({0,0,1}); 
       while(!pq.empty()){
            auto [a,b,c]=pq.top();
            pq.pop();
            if(b==n-1) return a;
            for(auto it:adj[b]){
                int v=it.first;
                int wt=it.second;
                int nxtcon=(labels[b]==labels[v])?c+1:1;
                if(nxtcon>k) continue;
                if(a+wt<dist[v][nxtcon]){
                    dist[v][nxtcon]=a+wt;
                    pq.push({a+wt,v,nxtcon});
                }
            }
       }
       return -1;
    }
};