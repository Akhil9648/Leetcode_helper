class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int active=count(s.begin(),s.end(),'1');
        vector<int>maxip;
        int curr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && curr>0){
                maxip.push_back(curr);
                curr=0;
            }
            else if(s[i]=='0') curr++;
        }
        if(curr>0) maxip.push_back(curr);
        int maxi=0;
        curr=0;
        if(maxip.size()<2) return active;
        for(int i=1;i<maxip.size();i++){
            curr=maxip[i]+maxip[i-1];
            maxi=max(maxi,curr);
        }
        return maxi+active;
    }
};