class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>arr(3,-1);
        int n=s.size();
        int cnt=0;
        int i=0;
        while(i<n){
            arr[s[i]-'a']=i;
            if(arr[0]!=-1 && arr[1]!=-1 && arr[2]!=-1){
                int a=min(arr[0],min(arr[1],arr[2]));
                cnt+=a+1;
            }
            i++;
        }
        return cnt;
    }
};