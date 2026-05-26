class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st;
        for(auto it:word){
            st.insert(it);
        }
        int cnt=0;
        for(auto it:word){
            if(st.count(it-'a'+'A')){
                cnt++;
                st.erase(it-'a'+'A');
            }
        }
        return cnt;
    }
};