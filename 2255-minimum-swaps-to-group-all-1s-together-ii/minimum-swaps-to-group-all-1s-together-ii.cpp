class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum=0,maxi=0;
        int i=0,j=0;
        int n=nums.size();
        int cnt=0;
        for(auto it:nums){
            if(it==1) cnt++;
        }
        while(j<cnt){
            sum+=nums[j];
            j++;
        }
        if(cnt==n) return 0;
        maxi=max(maxi,sum);
        while(i<n){
            sum-=nums[i];
            sum+=nums[j];
            i++;
            j=(j+1)%n;
            maxi=max(maxi,sum);
        }
        return cnt-maxi;
    }
};