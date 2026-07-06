class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pr=1,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pr*=nums[i];
            maxi=max(maxi,pr);
            if(pr==0) pr=1;
        }
        pr=1;
        for(int i=nums.size()-1;i>=0;i--){
            pr*=nums[i];
            maxi=max(maxi,pr);
            if(pr==0) pr=1;
        }
        return maxi;
    }
};