class Solution {
public:
    bool solve(int i,int j,string &s){
        if(i>=j) return true;
        if(s[i]==s[j]) return solve(i+1,j-1,s);
        return false;
    }
    string longestPalindrome(string s) {
        int st=-1,maxl=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
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