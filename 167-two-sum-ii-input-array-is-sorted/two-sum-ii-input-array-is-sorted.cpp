class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum>target) j--;
            else if(sum==target){
                return {i+1,j+1};
            }
            else i++;
        }
        return {-1,-1};
    }
};