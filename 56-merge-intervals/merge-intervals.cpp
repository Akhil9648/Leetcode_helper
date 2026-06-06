class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int st=intervals[0][0],end=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>end){
                ans.push_back({st,end});
                st=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};