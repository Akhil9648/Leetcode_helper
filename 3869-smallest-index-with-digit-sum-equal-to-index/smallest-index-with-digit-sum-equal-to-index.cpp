class Solution {
public:
    int findsum(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=findsum(nums[i]);
            if(i==a){
                return i;
            }
        }
        return -1;
    }
};