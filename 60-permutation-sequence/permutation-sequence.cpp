class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>s;
        for(int i=1;i<=n;i++) s.push_back(i);
        while(--k){
            next_permutation(s.begin(),s.end());
        }
        string ans;
        for(auto it:s) ans+=to_string(it);
        return ans;
        // return s;
    }
};