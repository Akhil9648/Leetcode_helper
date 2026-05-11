class Solution {
public:
    void append(int n,vector<int>& ans){
        vector<int>temp;
        while(n){
            int d=n%10;
            temp.push_back(d);
            n/=10;
        }
        reverse(temp.begin(),temp.end());
        for(auto &it:temp){
            ans.push_back(it);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &it:nums){
            append(it,ans);
        }
        return ans;
    }
};