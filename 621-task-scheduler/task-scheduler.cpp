class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>cnt(26,0);
        for(auto it:tasks){
            cnt[it-'A']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                pq.push(cnt[i]);
            }
        }
        int ans=0;
        vector<int>remain;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans++;
            if(it>1) remain.push_back(it-1);
            int b=n;
            if(pq.empty() && remain.empty()) break;
            while(b--){
                if(pq.empty() && remain.empty()) break;
                ans++;
                if(pq.size()>0){
                    auto k=pq.top();
                    pq.pop();
                    if(k>1) remain.push_back(k-1);
                }
            }
            for(auto i:remain) pq.push(i);
            remain.clear();
        }
        return ans;
    }
};