class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int sum=0,i=0,j=0,len=INT_MAX;
        string curr;
        while(j<n){
            if(s[j]=='1') sum++;
            while(sum==k){
                if(j-i+1<len){
                    len=j-i+1;
                    curr=s.substr(i,len);
                }
                else if(j-i+1==len){
                    string a=s.substr(i,len);
                    if(a<curr) curr=a;
                }
                if(s[i]=='1') sum--;
                i++;
            }
            j++;
        }
        return curr;
    }
};