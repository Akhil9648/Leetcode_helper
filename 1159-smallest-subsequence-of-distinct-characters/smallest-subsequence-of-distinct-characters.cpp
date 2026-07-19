class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>vis(26,0);
        unordered_map<char,int>mp;
        int i=0;
        int n=s.size();
        stack<char>st;
        while(i<n){
            mp[s[i]]=i;
            i++;
        }
        i=0;
        while(i<n){
            if(vis[s[i]-'a']==0){
                while(!st.empty()){
                    if(st.top()>=s[i] && mp[st.top()]>i){
                        vis[st.top()-'a']=0;
                        st.pop();
                    }
                    else break;
                }
                if(vis[s[i]-'a']==0){
                    st.push(s[i]);
                    vis[s[i]-'a']=1;
                }
            }
            i++;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};