class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0,ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};