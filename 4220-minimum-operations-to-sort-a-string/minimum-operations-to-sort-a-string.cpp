class Solution {
public:
    int minOperations(string s) {
        string target=s;
        sort(target.begin(),target.end());
        if(s==target) return 0;
        if(s.size()<=2) return -1;
        int n=target.size();
        char mini=target[0],maxi=target[n-1];
        if(s[0]==mini || s[n-1]==maxi) return 1;
        char max_mid=*max_element(s.begin()+1,s.end()-1);
        char min_mid=*min_element(s.begin()+1,s.end()-1);
        if(s[0]>max_mid && s[n-1]<min_mid) return 3;
        return 2;
    }
};