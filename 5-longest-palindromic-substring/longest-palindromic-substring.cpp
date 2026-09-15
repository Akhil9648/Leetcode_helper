class Solution {
public:
    bool isPal(int i,int j,string & s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    } 
    int len=0,st=0,n;
    void solve(int i,string &s){
        if(i>=n) return ;
        for(int j=i;j<n;j++){
            if(s[i]==s[j] && isPal(i,j,s)){
                if(j-i+1>len){
                    len=j-i+1;
                    st=i;
                }
            }
        }
        solve(i+1,s);
    }
    string longestPalindrome(string s) {
        n=s.size();
        solve(0,s);
        return s.substr(st,len);
    }
};