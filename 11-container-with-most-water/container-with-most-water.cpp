class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,ans=0;
        while(i<j){
            int a=min(height[i],height[j]);
            ans=max(ans,a*(j-i));
            if(height[i]>height[j]) j--;
            else if(height[i]<height[j]) i++;
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};