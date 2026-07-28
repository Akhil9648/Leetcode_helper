class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(auto it:s) freq[it-'a']++;
        int n=s.size();
        string ans(n,'.');
        int j=0;
        char mid;
        for(int i=0;i<26;i++){
            while(freq[i]>=2){
                ans[j]=char(i+'a');
                ans[n-j-1]=char(i+'a');
                freq[i]-=2;
                j++;
            }
            if(freq[i]==1) mid=char(i+'a');
        }
        if(n%2==1){
            ans[j]=mid;
        }
        return ans;
    }
};