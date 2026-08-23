class Solution {
public:
    bool solve(int i,int j,string &s,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s,dp);
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        int st=-1,maxl=0;
        int n=s.size();
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    if((j-i+1)>maxl){
                        maxl=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxl);
    }
};