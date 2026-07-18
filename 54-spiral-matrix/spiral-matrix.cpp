class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1;
        int left=0,right=m-1;
        int dir=0;
        vector<int>ans;
        while(top<=bottom && left<=right){
            if(dir==0){
                int a=left;
                while(a<=right){
                    ans.push_back(matrix[top][a]);
                    a++;
                }
                top++;
                dir=(dir+1)%4;
            }
            else if(dir==1){
                int a=top;
                while(a<=bottom){
                    ans.push_back(matrix[a][right]);
                    a++;
                }
                right--;
                dir=(dir+1)%4;
            }
            else if(dir==2){
                int a=right;
                while(a>=left){
                    ans.push_back(matrix[bottom][a]);
                    a--;
                }
                bottom--;
                dir=(dir+1)%4;
            }
            else if(dir==3){
                int a=bottom;
                while(a>=top){
                    ans.push_back(matrix[a][left]);
                    a--;
                }
                left++;
                dir=(dir+1)%4;
            }
        }
        return ans;
    }
};