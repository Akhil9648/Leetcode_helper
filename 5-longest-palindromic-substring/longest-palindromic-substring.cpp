class Solution {
public:
    string ans;
    bool isPal(int i,int j,string &s){
        int n=s.size();
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int j,string &s,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j] && isPal(i,j,s)){
            int size=j-i+1;
            if(size>ans.size()) ans=s.substr(i,size);
            return dp[i][j]=size;
        }
        if(j-i+1<ans.size()) return 0;
        int takel=solve(i+1,j,s,dp);
        int taker=solve(i,j-1,s,dp);
        return dp[i][j]= max(takel,taker);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(0,n-1,s,dp);
        return ans;
    }
};