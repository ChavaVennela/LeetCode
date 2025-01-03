class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]==target){
                return true;
            }
            if(matrix[i][0]>target){
                return false;
            }
            for(int j=1; j<matrix[i].size(); j++){
                if(matrix[i][j]==target){
                    return true;
                }
                if(matrix[i][j]>target){
                    break;
                }
            }
        }
        return false;
    }
};