class Solution1 {
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
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1=1e9,min2=1e9,max1=-1e9,max2=-1e9,max3=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<min2){
                if(nums[i]<min1){
                    min2=min1;
                    min1=nums[i];
                }
                else min2=nums[i];
            }
            if(nums[i]>max3){
                if(nums[i]>max1){
                    max3=max2;
                    max2=max1;
                    max1=nums[i];
                }
                else if(nums[i]>max2){
                    max3=max2;
                    max2=nums[i];
                }
                else max3=nums[i];
            }
        }
        return max(min1*min2*max1,max1*max2*max3);
    }
};