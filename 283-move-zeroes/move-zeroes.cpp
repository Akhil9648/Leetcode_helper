class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0,i=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==0){
                i=j+1;
                while(i<n){
                    if(nums[i]!=0){
                        swap(nums[i],nums[j]);
                        i++;
                        break;
                    }
                    i++;
                }
                if(i==n) break;
            }
            j++;
        }
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                for(int i=j+1;i<n;i++){
                    if(nums[i]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }
};