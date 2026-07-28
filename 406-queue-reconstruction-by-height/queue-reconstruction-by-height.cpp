class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto &a,const auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int n=people.size();
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int count=people[i][1];
            int val=people[i][0];
            int a=count;
            for(int j=0;j<n;j++){
                if(ans[j][0]==-1 && count==0){
                    ans[j][0]=val;
                    ans[j][1]=a;
                    break;
                }
                else if(people[i][0]<=ans[j][0] || ans[j][0]==-1) count--;
            }
        }
        return ans;
    }
};