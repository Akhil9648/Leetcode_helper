class Solution1 {
public:
    int n;
    bool isPal(int i,string &s,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string &s,int k,vector<int>& dp){
        if(i+k>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=solve(i+1,s,k,dp);
        for(int j=i+k-1;j<n;j++){
            if(s[i]==s[j] && isPal(i,s,j)){
                int a=1+solve(j+1,s,k,dp);
                take=max(a,take);
            }
        }
        return dp[i]=take;
    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,k,dp);
    }
};
class Solution {
public:
    int n;
    int solve(int i,string &s,int k,vector<int>& dp,vector<vector<bool>>& isPal){
        if(i+k>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=solve(i+1,s,k,dp,isPal);
        for(int j=i+k-1;j<n;j++){
            if(s[i]==s[j] && isPal[i][j]){
                int a=1+solve(j+1,s,k,dp,isPal);
                take=max(a,take);
            }
        }
        return dp[i]=take;
    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        vector<int>dp(n,-1);
        vector<vector<bool>>isPal(n,vector<bool>(n,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=l+i-1;
                if(s[i]==s[j]){
                    if(l<=2 || isPal[i+1][j-1]) isPal[i][j]=true;
                }
            }
        }
        return solve(0,s,k,dp,isPal);
    }
};