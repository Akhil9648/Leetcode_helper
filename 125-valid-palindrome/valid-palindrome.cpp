class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string a;
        for(auto it:s){
            if((it>='a' && it<='z') || (it>='0' && it<='9')) a.push_back(it);
        }
        s=a;
        reverse(a.begin(),a.end());
        return a==s;
    }
};