class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int curr1=INT_MAX;
        for(int i=0;i<n;i++){
            int a=landStartTime[i]+landDuration[i];
            curr1=min(curr1,a);
        }
        int comp=INT_MAX;
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=curr1){
                comp=min(comp,waterDuration[i]);
            }
            else{
                int a=waterStartTime[i]-curr1+waterDuration[i];
                comp=min(comp,a);
            }
        }
        curr1+=comp;
        int curr2=INT_MAX;
        for(int i=0;i<m;i++){
            int a=waterStartTime[i]+waterDuration[i];
            curr2=min(curr2,a);
        }
        comp=INT_MAX;
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=curr2){
                comp=min(comp,landDuration[i]);
            }
            else{
                int a=landStartTime[i]-curr2+landDuration[i];
                comp=min(comp,a);
            }
        }
        curr2+=comp;
        return min(curr1,curr2);
    }
};