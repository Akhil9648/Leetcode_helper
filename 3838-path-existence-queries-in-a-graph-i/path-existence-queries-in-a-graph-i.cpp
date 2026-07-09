class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n,-1);
        int cnt=0;
        comp[0]=0;
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])<=maxDiff) comp[i]=cnt;
            else{
                cnt++;
                comp[i]=cnt;
            }
            cout<<comp[i]<<" ";
        }
        vector<bool>ans;
        for(auto it:queries){
            if(comp[it[0]]==comp[it[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};