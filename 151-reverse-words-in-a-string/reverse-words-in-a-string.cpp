class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>word;
        string temp;
        while(ss>>temp) word.push_back(temp);
        reverse(word.begin(),word.end());
        string ans;
        for(auto &w:word){
            ans+=w;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};