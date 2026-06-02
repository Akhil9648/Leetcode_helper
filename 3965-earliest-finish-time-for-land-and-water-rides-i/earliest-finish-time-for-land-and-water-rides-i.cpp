class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(landStartTime[i]<waterStartTime[j]){
                    int curr=landStartTime[i]+landDuration[i];
                    if(curr<waterStartTime[j]){
                        curr+=(waterStartTime[j]-curr);
                    }
                    curr+=waterDuration[j];
                    ans=min(ans,curr);
                }
                else{
                    int curr=waterStartTime[j]+waterDuration[j];
                    if(curr<landStartTime[i]){
                        curr+=(landStartTime[i]-curr);
                    }
                    curr+=landDuration[i];
                    ans=min(ans,curr);
                }
            }
        }
        return ans;
    }
};