class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>result(k,0),prev(k,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<long long>curr(k,0);
            int currElementRemainder = nums[i]%k;
            curr[currElementRemainder]++;
            for(int x=0;x<k;x++){
                int nr=((long long)x*nums[i]%k)%k;
                curr[nr]+=prev[x];
            }
            prev=move(curr);
            for(int x=0;x<k;x++){
                result[x]+=prev[x];
            }
        }
        return result;
    }
};