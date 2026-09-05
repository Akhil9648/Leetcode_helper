class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(nums[i],mini[i+1]);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int a=maxi-mini[i];
            if(a<=k) return i;
        }
        return -1;
    }
};