class Solution1{
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
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int>pq2;
        for(auto it:nums){
            pq1.push(it);
            pq2.push(it);
        }
        int a=pq1.top();
        pq1.pop();
        int b=pq1.top();
        pq1.pop();
        int c=pq2.top();
        pq2.pop();
        int d=pq2.top();
        pq2.pop();
        int e=pq2.top();
        pq2.pop();
        return max(a*b*c,c*d*e);
    }
};