class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;
        vector<int>result;
        for(auto it:seq){
            if(it=='('){
                d++;
                result.push_back(d%2);
            }
            else{
                result.push_back(d%2);
                d--;
            }
        }
        return result;
    }
};