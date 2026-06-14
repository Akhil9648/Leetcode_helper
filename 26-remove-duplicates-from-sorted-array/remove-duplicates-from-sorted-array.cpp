class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,cnt=0;
        int n=nums.size();
        while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                cout<<nums[i]<<endl;
                nums.erase(nums.begin()+i);
                cnt++;
                i--;
            }
            i++;
        }
        return n-cnt;
    }
};