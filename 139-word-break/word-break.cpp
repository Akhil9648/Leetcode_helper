class Solution {
public:
    int n;
    bool solve(int i,string &s,unordered_set<string>& st,vector<int>& dp){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        string curr="";
        for(int j=i;j<n;j++){
            curr+=s[j];
            if(st.count(curr)){
                if(solve(j+1,s,st,dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it:wordDict) st.insert(it);
        n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,st,dp);
    }
};