class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>mp(nums.begin(),nums.end());
        int maxi=0;
        for(auto &it:mp){
            if(!mp.count(it-1)){
                int x=it;
                int curr=1;
                while(mp.count(x+1)){
                    curr++;
                    x++;
                }
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};