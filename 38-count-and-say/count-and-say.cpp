class Solution {
public:
    string cnt(string s){
        int n=s.size();
        int a=1;
        string ans="";
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                ans+=(to_string(a)+s[i]);
                a=1;
                continue;
            }
            a++;
        }
        if(a>0){
            ans+=(to_string(a)+s[n-1]);
        }
        return ans;
    }
    string countAndSay(int n) {
        string a="1";
        while(--n){
            a=cnt(a);
        }
        return a;
    }
};