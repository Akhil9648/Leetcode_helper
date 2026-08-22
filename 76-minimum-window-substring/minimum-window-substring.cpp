class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int n=s.size();
        int m=t.size();
        int i=0,j=0,st=0,l=n+1,cnt=0;
        while(j<n){
            if(mp[s[j]]>0) cnt++;
            mp[s[j]]--;
            while(cnt==m){
                if(j-i+1<l){
                    l=j-i+1;
                    st=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
            j++;
        }
        if(l==n+1) return "";
        return s.substr(st,l);
    }
};