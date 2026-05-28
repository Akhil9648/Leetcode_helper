class Solution {
public:
    void sortColors(vector<int>& arr) {
        // int n=arr.size();
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            }
        }
    }
};