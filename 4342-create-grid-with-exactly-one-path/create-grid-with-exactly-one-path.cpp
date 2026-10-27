class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        while(--m){
            string s(n,'#');
            s[0]='.';
            ans.push_back(s);
        }
        string s(n,'.');
        ans.push_back(s);
        return ans;
    }
};