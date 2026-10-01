class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int>pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) pos.push_back(i);
        }
        if(pos.size()<k) return -1;
        int m=pos.size();
        vector<long long>pref(m+1,0);
        pref[0]=pos[0];
        for(int i=0;i<m;i++){
            pref[i+1]=(pref[i]+pos[i]);
        }
        long long ans=LLONG_MAX;
        int l=0,r=k-1;
        while(r<m){
            int mid=(l+r)/2;
            if(k%2==0){
                long long rsum=pref[r+1]-pref[mid+1];
                long long lsum=pref[mid]-pref[l];
                long long moves=rsum-lsum-pos[mid];
                long long radius=(mid-l);
                long long move=radius*(radius+1)+(radius+1);
                moves-=move;
                ans=min(ans,moves);
            }
            else{
                long long rsum=pref[r+1]-pref[mid+1];
                long long lsum=pref[mid]-pref[l];
                long long moves=rsum-lsum;
                long long radius=(mid-l);
                long long move=radius*(radius+1);
                moves-=move;
                ans=min(ans,moves);
            }
            l++;
            r++;
        }
        return ans;
    }
};