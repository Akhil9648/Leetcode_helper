class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(auto it:nums) st.insert(it);
        int maxi=0;
        for(auto it:nums){
            int a=it;
            while(st.count(a-1)) a--;
            int cnt=0;
            while(st.count(a)){
                cnt++;
                st.erase(a);
                a++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};