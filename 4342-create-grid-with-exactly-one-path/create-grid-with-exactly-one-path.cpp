class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string s(n,'#');
        s[0]='.';
        while(--m){
            ans.push_back(s);
        }
        string t(n,'.');
        ans.push_back(t);
        return ans;
    }
};