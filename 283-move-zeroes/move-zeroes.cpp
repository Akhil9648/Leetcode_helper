class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(auto it:nums){
            if(it!=0) cnt++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                if(cnt>0) i--;
                cout<<i<<" ";
            }
            else cnt--;
        }
    }
};