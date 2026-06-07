class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>st;
        int miss=0;
        int n=grid.size();
        for(auto it:grid){
            for(auto i:it){
                if(st.count(i)) miss=i;
                st.insert(i);
            }
        }
        for(int i=1;i<=n*n;i++){
            if(!st.count(i)) return {miss,i};
        }
        return {0,0};
    }
};