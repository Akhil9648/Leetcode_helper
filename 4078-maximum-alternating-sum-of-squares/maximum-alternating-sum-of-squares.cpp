class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end(),[](const auto &a,const auto &b){
            return abs(a)<abs(b);
        });
        int n=nums.size();
        int i=0,j=n-1,flag=1;
        while(i<=j){
            if(flag){
                ans+=(nums[j]*nums[j]);
                j--;
                flag=!flag;
            }
            else{
                ans-=(nums[i]*nums[i]);
                i++;
                flag=!flag;
            }
        }
        return ans;
    }
};