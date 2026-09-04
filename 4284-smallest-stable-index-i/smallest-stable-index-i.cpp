class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefmin(n,1e9);
        prefmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefmin[i]=min(nums[i],prefmin[i+1]);
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int a=maxi-prefmin[i];
            if(a<=k){
                return i;
            }
        }
        return -1;
    }
};