class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>mp;
        int m=chars.size();
        for(int i=0;i<m;i++){
            mp[chars[i]]=vals[i];
        }
        int n=s.size();
        int curr=0,maxi=0;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])) curr+=mp[s[i]];
            else curr+=(s[i]-'a'+1);
            maxi=max(maxi,curr);
            if(curr<0) curr=0;
        }
        return maxi;
    }
};