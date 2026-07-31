class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(auto it:word){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int cnt=0;
        vector<int>val(26,0);
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            val[it.second-'a']=(cnt/8)+1;
            cnt++;
        }
        int ans=0;
        for(auto it:val) cout<<it<<" ";
        for(auto it:word){
            ans+=val[it-'a'];
        }
        return ans;
    }
};