class Solution {
public:
    string ans(string &curr){
        int n=curr.size();
        int a=1;
        char b=curr[0];
        string res;
        for(int i=1;i<n;i++){
            if(curr[i]!=b){
                res.push_back(a+'0');
                res.push_back(b);
                a=1;
                b=curr[i];
            }
            else a++;
        }
        res.push_back(a+'0');
        res.push_back(b);
        return res;
    }
    string countAndSay(int n) {
        string curr="1";
        while(--n){
            curr=ans(curr);
        }
        return curr;
    }
};