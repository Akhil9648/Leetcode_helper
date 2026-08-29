class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int cnt=0;
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>mp1;
        mp[0].push_back(vec[0]);
        mp1[vec[0]]=cnt;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit) cnt++;
            mp[cnt].push_back(vec[i]);
            mp1[vec[i]]=cnt;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int a=mp1[nums[i]];
            ans.push_back(mp[a][0]);
            mp[a].erase(mp[a].begin());
        }
        return ans;
    }
};