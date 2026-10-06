class Solution {
public:
    int minAddToMakeValid(string s) {
        int unb=0;
        stack<int>st;
        for(auto it:s){
            if(it=='(') st.push(it);
            else{
                if(!st.empty()) st.pop();
                else unb++;
            }
        }
        return st.size()+unb;
    }
};