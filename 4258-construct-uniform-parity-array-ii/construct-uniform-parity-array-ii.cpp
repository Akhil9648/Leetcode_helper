class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=1e9;
        int odd=0,even=0;
        for(auto it:nums1){
            if(it%2){
                odd++;
                mini=min(mini,it);
            }
            else even++;
        }
        if(odd==0 || even==0) return true;
        bool e=true,o=true;
        for(auto it:nums1){
            if(it%2==0){
                if(mini>=it) o=false;
            }
            if(it%2==1){
                if(mini>=it) e=false;
            }
        }
        return o||e;
    }
};