class Solution {
public:
    int minAddToMakeValid(string s) {
        int unb=0,op=0;
        for(auto it:s){
            if(it=='(') op++;
            else{
                if(op>0) op--;
                else unb++;
            }
        }
        return op+unb;
    }
};