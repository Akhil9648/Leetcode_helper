class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);
        for(auto &it:s){
            freq[it-'a']++;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==1) return i;
        }
        return -1;
    }
};