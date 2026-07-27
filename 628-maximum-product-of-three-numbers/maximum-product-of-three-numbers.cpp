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