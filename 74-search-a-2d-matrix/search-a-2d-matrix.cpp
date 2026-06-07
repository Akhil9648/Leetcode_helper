class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                for(int j=0;j<m;j++) if(matrix[i][j]==target) return true;
            }
            else if(target<matrix[i][0]) return false;
        }
        return false;
    }
};