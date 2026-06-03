class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>>arr1,arr2;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            arr1.push_back({landStartTime[i],landDuration[i]});
        }
        for(int j=0;j<m;j++){
            arr2.push_back({waterStartTime[j],waterDuration[j]});
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int curr1=INT_MAX;
        for(int i=0;i<n;i++){
            int a=arr1[i].first+arr1[i].second;
            curr1=min(curr1,a);
        }
        int comp=INT_MAX;
        for(int i=0;i<m;i++){
            if(arr2[i].first<=curr1){
                comp=min(comp,arr2[i].second);
            }
            else{
                int a=arr2[i].first-curr1+arr2[i].second;
                comp=min(comp,a);
            }
        }
        curr1+=comp;
        int curr2=INT_MAX;
        for(int i=0;i<m;i++){
            int a=arr2[i].first+arr2[i].second;
            curr2=min(curr2,a);
        }
        comp=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr1[i].first<=curr2){
                comp=min(comp,arr1[i].second);
            }
            else{
                int a=arr1[i].first-curr2+arr1[i].second;
                comp=min(comp,a);
            }
        }
        curr2+=comp;
        return min(curr1,curr2);
    }
};