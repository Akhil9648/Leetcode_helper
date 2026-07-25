class Solution {
public:
    bool ship(int mid,vector<int>& weights,int days){
        int curr=0,time=1;
        for(auto &it:weights){
            if(curr+it>mid){
                curr=it;
                time++;
            }
            else curr+=it;
        }
        return time<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        for(auto &it:weights) high+=it;
        int low=*max_element(weights.begin(),weights.end());
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(ship(mid,weights,days)){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};