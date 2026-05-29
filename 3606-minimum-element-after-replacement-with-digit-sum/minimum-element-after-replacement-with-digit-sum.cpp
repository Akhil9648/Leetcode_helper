class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n){
            int d=n%10;
            ans+=d;
            n/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto it:nums){
            mini=min(mini,sum(it));
        }
        return mini;
    }
};