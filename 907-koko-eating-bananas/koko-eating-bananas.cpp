class Solution {
public:
    bool solve(vector<int>& piles,int h,int k){
        int cnt=0;
        for(auto it:piles){
            int a=it/k;
            if(it%k>0){
                a++;
            }
            cnt+=a;
            if(cnt>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};