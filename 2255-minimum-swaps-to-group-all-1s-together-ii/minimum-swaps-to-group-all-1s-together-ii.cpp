class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(auto it:nums){
            a+=it;
        }
        int i=0,curr=0,maxi=0;
        for(;i<a;i++){
            curr+=nums[i];
        }
        int j=0;
        maxi=max(maxi,curr);
        for(int i=a;i<2*n;i++){
            curr-=nums[j%n];   
            j++;
            curr+=nums[i%n];
            maxi=max(maxi,curr);
        }
        return a-maxi;
    }
};