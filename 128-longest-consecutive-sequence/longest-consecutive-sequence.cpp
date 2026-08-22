class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(auto it:nums) st.insert(it);
        int maxi=0;
        for(auto &it:st){
            int a=it;
            if(st.count(a-1)) continue;
            int cnt=0;
            while(st.count(a)){
                cnt++;
                a++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};