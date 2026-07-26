class Solution1 {
public:
    int n;
    int solve(int i,vector<int>& nums,int cnt,int mul){
        if(cnt==0) return mul;
        if(i>=n) return -1e9;
        if(i>=n) return 1;
        int take=solve(i+1,nums,cnt-1,mul*nums[i]);
        int notTake=solve(i+1,nums,cnt,mul);
        return max(take,notTake);
    }
    int maximumProduct(vector<int>& nums) {
        n=nums.size();
        return solve(0,nums,3,1);
    }
};
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a=nums[0],b=nums[1],c=nums[n-1];
        int mul=a*b*c;
        a=nums[n-1],b=nums[n-2],c=nums[n-3];
        mul=max(mul,a*b*c);
        return mul;
    }
};