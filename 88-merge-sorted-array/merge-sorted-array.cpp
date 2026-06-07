class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m+n && j<n){
            if(nums1[i]>nums2[j]){
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
                // i--;
            }
            else i++;
        }
        int a=n;
        while(a--) nums1.pop_back();
        while(j<n){
            nums1.push_back(nums2[j]);
            j++;
        }
    }
};