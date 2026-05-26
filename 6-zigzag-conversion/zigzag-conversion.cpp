class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>arr(numRows);
        int n=s.size();
        if(numRows==1 || numRows>=n) return s;
        int k=0,flag=0;
        for(int i=0;i<n;i++){
            arr[k].push_back(s[i]);
            if(flag) k--;
            else k++;
            if(k==numRows){
                k-=2;
                flag=!flag;
            }
            if(k==0 && flag){
                flag=!flag;
            }
        }
        string ans;
        for(int i=0;i<numRows;i++){
            for(auto j:arr[i]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};