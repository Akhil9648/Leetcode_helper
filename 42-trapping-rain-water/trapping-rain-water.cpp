class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pge,nge(n);
        int maxi=0;
        for(auto it:height){
            maxi=max(maxi,it);
            pge.push_back(maxi);
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            nge[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int a=min(pge[i],nge[i]);
            int curr=a-height[i];
            ans+=curr;
        }
        return ans;
    }
};