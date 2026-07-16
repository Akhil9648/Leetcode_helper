class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int>ans;
        int mx=0;
        for(auto &it:nums){
            mx=max(it,mx);
            it=gcd(it,mx);
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            if(i==j) return nums[i];
            int a=gcd(nums[i],nums[j]);
            ans.push_back(a);
            i++;
            j--;
        }
        long long res=0;
        for(auto &it:ans){
            res+=it;
        }
        return res;
    }
};