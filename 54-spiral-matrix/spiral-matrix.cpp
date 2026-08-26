class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,bottom=n-1;
        int l=0,r=m-1,dir=0;
        vector<int>ans;
        while(top<=bottom && l<=r){
            if(dir==0){
                int ptr=l;
                while(ptr<=r){
                    ans.push_back(matrix[top][ptr]);
                    ptr++;
                }
                dir=(dir+1)%4;
                top++;
            }
            else if(dir==1){
                int ptr=top;
                while(ptr<=bottom){
                    ans.push_back(matrix[ptr][r]);
                    ptr++;
                }
                dir=(dir+1)%4;
                r--;
            }
            else if(dir==2){
                int ptr=r;
                while(ptr>=l){
                    ans.push_back(matrix[bottom][ptr]);
                    ptr--;
                }
                dir=(dir+1)%4;
                bottom--;
            }
            else{
                int ptr=bottom;
                while(ptr>=top){
                    ans.push_back(matrix[ptr][l]);
                    ptr--;
                }
                dir=(dir+1)%4;
                l++;
            }
        }
        return ans;
    }
};