class Solution1 {
public:
    string getPermutation(int n, int k) {
        vector<int>s;
        for(int i=1;i<=n;i++) s.push_back(i);
        while(--k){
            next_permutation(s.begin(),s.end());
        }
        string ans;
        for(auto it:s) ans+=to_string(it);
        return ans;
        // return s;
    }
};
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact=1;
        for(int i=1;i<n;i++){
            nums.push_back(i);
            fact=fact*i;
        }
        nums.push_back(n);
        k--;
        string s;
        while(1){
            s+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k%=fact;
            fact/=nums.size();
        }
        return s;
    }
};