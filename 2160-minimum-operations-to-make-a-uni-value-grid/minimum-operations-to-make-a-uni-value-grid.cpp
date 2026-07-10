class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(auto it:grid[i]){
                arr.push_back(it);
            }
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        n/=2;
        int a=arr[n];
        int cnt=0;
        for(auto it:arr){
            int b=abs(it-a);
            if(b%x!=0) return -1;
            cnt+=b/x;
        }
        return cnt;
    }
};