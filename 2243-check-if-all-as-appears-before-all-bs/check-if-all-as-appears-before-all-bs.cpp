class Solution {
public:
    bool checkString(string s) {
        bool found=false;
        for(auto it:s){
            if(it=='b') found=true;
            else{
                if(found) return false;
            }
        }
        return true;
    }
};