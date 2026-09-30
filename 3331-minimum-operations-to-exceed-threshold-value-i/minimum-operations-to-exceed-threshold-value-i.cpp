class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        for(auto it:nums){
            if(it<k) cnt++;
        }
        return cnt;
    }
};