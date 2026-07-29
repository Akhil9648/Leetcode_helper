class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int,vector<int>,greater<int>>mini;
        priority_queue<int>maxi;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                mini.push(nums1[i]);
                i++;
            }
            else{
                mini.push(nums2[j]);
                j++;
            }
            if(mini.size()>maxi.size()){
                int a=mini.top();
                mini.pop();
                maxi.push(a);
            }
        }
        while(i<n){
            mini.push(nums1[i]);
            i++;
            if(mini.size()>maxi.size()){
                int a=mini.top();
                mini.pop();
                maxi.push(a);
            }
        }
        while(j<m){
            mini.push(nums2[j]);
            j++;
            if(mini.size()>maxi.size()){
                int a=mini.top();
                mini.pop();
                maxi.push(a);
            }
        }
        if((n+m)%2==0){
            return (maxi.top()+mini.top())/2.0;
        }
        return maxi.top()/1.0;
    }
};