class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prev;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            prev.push_back(maxi);
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            prev[i]=min(prev[i],maxi);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int a=prev[i]-height[i];
            sum+=a;
        }
        return sum;
    }
};