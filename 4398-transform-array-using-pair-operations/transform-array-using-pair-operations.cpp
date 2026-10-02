class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long a=0,b=0;
        for(auto it:source) a+=it;
        for(auto it:target) b+=it;
        return a==b;
    }
};