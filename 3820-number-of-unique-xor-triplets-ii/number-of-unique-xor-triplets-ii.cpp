class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st,fin;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto it:st){
            for(int i=0;i<n;i++){
                fin.insert(it^nums[i]);
            }
        }
        return fin.size();
    }
};