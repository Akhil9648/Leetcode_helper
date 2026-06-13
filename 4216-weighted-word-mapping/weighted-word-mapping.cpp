class Solution {
public:
    int solve(string& s,vector<int>& weights){
        int sum=0;
        for(auto it:s){
            sum+=weights[it-'a'];
        }
        return sum%26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto it:words){
            int sum=solve(it,weights);
            ans+=((26-sum-1)+'a');
        }
        return ans;
    }
};