class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int high=points[0][1];
        int n=points.size();
        int ans=1;
        for(int i=1;i<n;i++){
            if(points[i][0]<=high){
                high=min(high,points[i][1]);
            }
            else{
                ans++;
                high=points[i][1];
            }
        }
        return ans;
    }
};