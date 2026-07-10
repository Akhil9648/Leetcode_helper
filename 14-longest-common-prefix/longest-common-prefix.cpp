class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curr=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            int m=strs[i].size();
            if(m<curr.size()){
                curr=curr.substr(0,m);
            }
            for(int j=0;j<min(curr.size(),strs[i].size());j++){
                if(curr[j]!=strs[i][j]){
                    curr=curr.substr(0,j);
                }
            }
        }
        return curr;
    }
};