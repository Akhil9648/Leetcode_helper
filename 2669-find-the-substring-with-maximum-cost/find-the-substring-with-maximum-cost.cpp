class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>mp;
        int n=s.size();
        int m=chars.size();
        for(int i=0;i<m;i++){
            mp[chars[i]]=vals[i];
        }
        int curr=0,maxi=0,value;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])) value=mp[s[i]];
            else value=s[i]-'a'+1;
            curr+=value;
            if(curr<0) curr=0;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};