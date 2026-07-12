class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>cpy=arr;
        int n=arr.size();
        int cnt=1;
        sort(cpy.begin(),cpy.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(!mp.count(cpy[i])) mp[cpy[i]]=cnt++;
        }
        for(int i=0;i<n;i++){
            cpy[i]=mp[arr[i]];
        }
        return cpy;
    }
};