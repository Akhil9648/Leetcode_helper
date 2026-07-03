class Solution {
public:
    int n;
    bool solve(unordered_map<int,vector<vector<int>>>& mp,long long k,int mini){
        vector<long long>res(n,LLONG_MAX);
        res[0]=0;
        priority_queue<pair<long long,int>,
               vector<pair<long long,int>>,
               greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cst, node] = pq.top();
            pq.pop();
            if (cst != res[node]) continue;
            if(cst>k) continue;
            if(node==n-1) return true;
            for(auto a:mp[node]){
                int cost=a[1];
                int nd=a[0];
                if(cost<mini) continue;
                if(res[nd]>cost+cst){
                    res[nd]=cost+cst;
                    pq.push({cost+cst,nd});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        unordered_map<int,vector<vector<int>>>mp;
        int maxi=0,mini=INT_MAX;
        for(auto it:edges){
            if(it[1]!=n-1 && !online[it[1]]) continue;
            mp[it[0]].push_back({it[1],it[2]});
            mini=min(mini,it[2]);
            maxi=max(maxi,it[2]);
        }
        int low=mini,high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            vector<int>vis(n,0);
            if(solve(mp,k,mid)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};