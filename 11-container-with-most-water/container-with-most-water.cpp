class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,maxi=0;
        while(i<j){
            int mini=min(height[i],height[j]);
            int a=mini*(j-i);
            maxi=max(maxi,a);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};