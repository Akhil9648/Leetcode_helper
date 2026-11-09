class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        priority_queue<int, vector<int>, greater<int>> avail;
        int i=0;
        int maxi=0;
        while(i<k){
            avail.push(i);
            i++;
        }
        vector<int>cnt(k,0);
        int n=arrival.size();
        for(i=0;i<n;i++){
            while(!busy.empty()){
                auto it=busy.top();
                if(it.first<=arrival[i]){
                    avail.push(i + (it.second - i % k + k) % k);
                    busy.pop();
                }
                else{
                    break;
                }
            }
            if(!avail.empty()){
                auto it = avail.top() % k;
                busy.push({arrival[i]+load[i],it});
                cnt[it]++;
                maxi=max(maxi,cnt[it]);
                avail.pop();
            }
        }
        vector<int>ans;
        for(i=0;i<k;i++){
            if(cnt[i]==maxi) ans.push_back(i);
        }
        return ans;
    }
};