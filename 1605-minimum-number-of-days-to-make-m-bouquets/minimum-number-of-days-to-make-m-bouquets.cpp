class Solution {
public:
    bool possible(int day,vector<int>& bloom,int m,int k){
        int cnt=0;
        int n=bloom.size();
        for(int i=0;i<n;i++){
            if(bloom[i]<=day){
                cnt++;
                if(cnt==k){
                    cnt=0;
                    m--;
                }
            }
            else{
                cnt=0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,bloomDay,m,k)){
                high=mid-1;
                ans=mid;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};