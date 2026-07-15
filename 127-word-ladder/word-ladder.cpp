class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int n=beginWord.length();
        int ans=INT_MAX;
        if(!st.count(endWord)) return 0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string curr=it.first;
            int dis=it.second;
            if(curr==endWord) return dis;
            for(int i=0;i<n;i++){
                char c=curr[i];
                for(int j=0;j<26;j++){
                    curr[i]='a'+j;
                    if(st.count(curr)){
                        q.push({curr,dis+1});
                        st.erase(curr);
                    }
                }
                curr[i]=c;
            }
        }
        return 0;
    }
};