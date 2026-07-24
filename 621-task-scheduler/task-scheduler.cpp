class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>>pq;
        vector<int>cnt(26,0),pri(26,0);
        for(auto it:tasks){
            cnt[it-'A']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                pq.push({cnt[i],i});
            }
        }
        int ans=0;
        while(!pq.empty()){
            priority_queue<pair<int,int>>cu;
                for(int i=0;i<26;i++){
                    pri[i]--;
                }
            while(!pq.empty()){
                auto it=pq.top();
                int c=it.first;
                int curr=it.second;
                if(pri[curr]<0){
                    pq.pop();
                    if(c>1) pq.push({c-1,curr});
                    pri[curr]=n;
                    break;
                }
                else{
                    cu.push(it);
                    pq.pop();
                }
            }
            while(!cu.empty()){
                auto it=cu.top();
                pq.push(it);
                cu.pop();
            }
            ans++;
        }
        return ans;
    }
};